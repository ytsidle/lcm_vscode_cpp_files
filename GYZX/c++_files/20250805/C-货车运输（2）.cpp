#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10,M=5e4+10;
int n,m,st[2*N][24];
int f[2*N],dep[2*N],num[2*N];
vector<int> g[N];
struct Edge {
	int u,v,w;
} e[M];
int find(int x) {
	return x==f[x]?x:f[x]=find(f[x]);
}
void dfs(int now,int c){
    dep[now]=c;
    for(int to:g[now]){
        if(to==st[now][0])continue;
        st[to][0]=now;
        dfs(to,c+1);
    }
}
inline bool  cmp(Edge a,Edge b) {
	return a.w>b.w;
}
inline int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;i--){
		if((1<<i)<=(dep[x]-dep[y])){
			x=st[x][i];
		}
	}
	if(x==y) return x;
	for(int i=19;i>=0;i--){
		if(st[x][i]!=st[y][i]){
			x=st[x][i];
			y=st[y][i];
		}
	}return st[x][0];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<2*n; i++) {
		f[i]=i;
	}
	int cnt=n;
	for(int i=1; i<=m; i++) {
		cin>>e[i].u>>e[i].v>>e[i].w;

	}
	sort(e+1,e+1+m,cmp);
	for(int i=1; i<=m; i++) {
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)!=find(v)) {
			++cnt;
			g[cnt].push_back(find(u));
			g[cnt].push_back(find(v));
			f[find(u)]=cnt;
			f[find(v)]=cnt;
			num[cnt]=w;
			
		}
	}
	++cnt;
	f[cnt]=cnt;
	num[cnt]=-1;
	for(int i=1; i<cnt; i++) {
		if(f[i]==i) {
			f[i]=cnt;g[cnt].push_back(i);
		}
	}
	dfs(cnt,0);
	for(int j=1; j<=19; j++) {
		for(int i=1; i<=cnt; i++) {
			st[i][j]=st[st[i][j-1]][j-1];
		}
	}
	int q;
	cin>>q;
	for(int i=1; i<=q; i++) {
		int x,y;
		cin>>x>>y;
		int lc=lca(x,y);
		cout<<num[lc]<<"\n";
	}
	return 0;
}