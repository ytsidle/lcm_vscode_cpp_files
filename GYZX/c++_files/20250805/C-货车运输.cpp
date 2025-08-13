#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=5e4+10;
int n,m,st[2*N][24];
int f[2*N],dep[2*N],num[2*N];
vector<int>
struct Edge {
	int u,v,w;
} e[M];
int find(int x) {
	return x==f[x]?x:f[x]=find(f[x]);
}
void dfs(int now,int fa,int dp) {
	dep[now]=dp;
	for(int to:g[now]) {
		st[to][0]=now;
		dfs(to,now,dp+1);
	}
}
bool  cmp(Edge a,Edge b) {
	return a.w>b.w;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=2*n; i++) {
		f[i]=i;
	}
	int cnt=n;
	for(int i=1; i<=m; i++) {
		cin>>e[i].u>>e[i].v>>e[i].w;

	}
	sort(e+1,e+1+m);
	for(int i=1; i<=m; i++) {
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)!=find(v)) {
			++cnt;
			f[find(u)]=cnt;
			f[find(v)]=cnt;
			g[cnt].push_back(find(u));
			g[cnt].push_back(find(v));
			num[i]
		}
	}
	++cnt;
	for(int i=1; i<cnt; i++) {
		if(f[i]==i) {
			f[i]=cnt;
		}
	}
	dfs(cnt,0,0);
	for(int j=1; j<=19; j++) {
		for(int i=1; i<=cnt; i++) {
			st[i][j]=st[st[i][j-1]][j-1];
		}
	}
	int q;
	for(int i=1; i<=n; i++) {
		int x,y;
	}
	return 0;
}