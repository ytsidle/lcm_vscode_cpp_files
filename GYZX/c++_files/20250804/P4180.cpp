#include <bits/stdc++.h>
#define int long long
#define aaaas == bbbbs !(aaaas^bbbbs)
#define aas != bbs aas^bbs
using namespace std;
using pii = pair<int,int> ;
const int error=LLONG_MIN;
const int M=3e5+1,N=3e5+1;
struct Edge {
	int x,y,z,flag;
	bool operator<(const Edge b) const
	{
		return z<b.z;
	}
} e[M];
int f[N],st[N][24],mx[N][24],mx2[N][24],dep[N];
vector<pii> g[N];
inline void init(int num)
{
	for(register int i=1; i<=num; i++) {
		f[i]=i;
	}
}
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
void dfs(int now,int fa)
{
//	cout<<now<<" dfs\n";
	for(auto tmp:g[now]) {
		int to=tmp.first,ww=tmp.second;
		if(to==fa) continue;
		dep[to]=dep[now]+1,st[to][0]=now,mx[to][0]=ww,mx2[to][0]=error;
		dfs(to,now);
	}
}
int n,m;
inline int lca(int x,int y,int avoid)
{
	int ag=LONG_LONG_MIN;
	if(dep[x]<dep[y]) swap(x,y);
	int mxx=error,myy=error;
	for(register int i=19; i+1; i--) {
		if((1<<i)<=(dep[x]-dep[y])) {
			ag=max(ag,avoid==mx[x][i]?mx2[x][i]:mx[x][i]),x=st[x][i];
		}
	}
	if(x==y)return ag;
	for(register int i=19; i+1; i--) {
		if(st[x][i]!=st[y][i]&&st[x][i]&&st[y][i]) {
			ag=max(ag,avoid==max(mx[x][i],mx[y][i])?(mx[x][i]==mx[y][i]?max(mx2[x][i],mx2[y][i]):min(mx[x][i],mx[y][i])):(max(mx[x][i],mx[y][i]))),x=st[x][i],y=st[y][i];
		}
	}
	register int i=0;
	ag=max(ag,avoid==max(mx[x][i],mx[y][i])?(mx[x][i]==mx[y][i]?max(mx2[x][i],mx2[y][i]):min(mx[x][i],mx[y][i])):(max(mx[x][i],mx[y][i])));
	return ag;
}
main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		int x,y,z;
		cin>>x>>y>>z;
		e[i]= {x,y,z,0};
	}
	init(n),sort(e+1,e+1+m);
	int cnt=0,bsum=0;
	for(register int i=1; i<=m; i++) {
		int u=e[i].x,v=e[i].y,w=e[i].z;
		if(u==v) continue;
		int fu=find(u),fv=find(v);
		if(fu!=fv) {
			cnt++,bsum+=w,f[fu]=fv,e[i].flag=1,g[u].push_back({v,w}),g[v].push_back({u,w});
			if(cnt==n-1)break;
		}
	}
	dep[1]=0;
	mx[1][0]=error;
	dfs(1,0);
	for(register int j=1; j<=19; j++) {
		for(register int i=1; i<=n; i++) {
			if(i+(1<<(j-1))>n+1) continue;
			st[i][j]=st[st[i][j-1]][j-1],mx[i][j]=max(mx[i][j-1],mx[st[i][j-1]][j-1]);
			if(mx[i][j-1]==mx[st[i][j-1]][j-1]) mx2[i][j]=max(mx2[i][j-1],mx2[st[i][j-1]][j-1]);
			else mx2[i][j]=max(min(mx[i][j-1],mx[st[i][j-1]][j-1]),max(mx2[i][j-1],mx2[st[i][j-1]][j-1]));
		}
	}
	int ans=LONG_LONG_MAX;
	for(register int i=1; i<=m; i++) {
		if(e[i].flag) continue;
		//枚举非生成树边
		int u,v,w;
		u=e[i].x,v=e[i].y,w=e[i].z;
		int re=lca(u,v,w);
		if(re==error) continue;
		ans=min(ans,bsum+w-re);
	}
	cout<<ans;
}