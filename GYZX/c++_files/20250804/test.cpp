#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+10,M=5e4+10;
int n,m;
int f[2*N],st[2*N][24],num[2*N];
vector<int > g[2*N];
struct Edge {
	int u,v,w;
	bool operator<(const Edge& b) const
	{
		return w>b.w;
	}
} e[M];
int find(int x)
{
	return x==f[x]?x:f[x]=find(f[x]);
}
int dep[2*N];
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=19; i>=0; i--) {
		if((dep[x]-dep[y])>=(1<<i)) {
			x=st[x][i],y=st[y][i];
		}
	}
	if(x==y) {
		return x;
	} 
	for(int i=19;i>=0;i--){
		if(st[x][i]!=st[y][i]&&st[x][i]&&st[y][i]){
			x=st[x][i],y=st[y][i];
		}
	}return st[x][0];
}

void dfs(int now,int fa,int dp)
{
	dep[now]=dp,st[now][0]=fa;
	for(int to:g[now]) {
		if(to==fa) continue;
		dep[to]=dp+1;
		dfs(to,now,dp+1);
	}
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<2*n; i++) f[i]=i;
	for(int i=1; i<=m; i++) {
		int x,y,z;
		cin>>x>>y>>z;
		e[i*2-1]= {x,y,z},e[i*2]={y,x,z};
	}
	int cnt=n;
	sort(e+1,e+1+m);
	for(int i=1; i<=m; i++) {
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy){
			num[++cnt]=e[i].w;
			f[fy]=cnt,f[fx]=cnt;
			st[fy][0]=cnt,st[fx][0]=cnt;
			g[cnt].push_back(fx);
			g[cnt].push_back(fy);
			
		}
	}
	++cnt,f[cnt]=0,st[cnt][0]=0,num[cnt]=-1;
	for(int i=1; i<cnt; i++) {
		if(st[i][0]==0){
			st[i][0]=cnt;
			g[cnt].push_back(i);
		}
	}
	for(int i=1; i<=19; i++) {
		for(int j=1; j<=cnt; j++) {
			st[j][i]=st[st[j][i-1]][i-1];
		}
	}
	dfs(cnt,0,1);
	for(int i=1;i<=cnt;i++)cout<<dep[i]<<"  ff \n";
	int qq;cin>>qq;
	while(qq--){
		int x,y;cin>>x>>y;
		int re=lca(x,y);
		if(re==cnt)cout<<-1<<"\n";
		else cout<<num[re]<<'\n';
	}
}