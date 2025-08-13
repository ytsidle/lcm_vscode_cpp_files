#include <bits/stdc++.h>
using namespace std;
const int  N=5050;
#define ll long long 
using pll=pair<ll,ll>;
long long f[N],k,sum,n,m,vis[N];
vector<pll > g[N];
long long find(long long x){
	return f[x]==x?x:f[x]=find(f[x]);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		long long x,y,z;
		cin>>x>>y>>z;
		g[x].push_back({y,z});
		g[y].push_back({x,z});
	}
	//prim
	memset(f,0x3f,sizeof(f));
	int k=0;
	priority_queue<pll,deque<pll>,greater<pll> > q;
	q.push({0,1});
	f[1]=0;
	while(!q.empty()){
		k++;
		pll h=q.top();
		q.pop();
		int dd=h.first,now=h.second;
		if(dd>f[now]||vis[now]){
			continue;
		}
		sum+=f[now];
		vis[now]=1;
		for(auto tmp:g[now]){
			int to=tmp.first,ww=tmp.second;
			if(!vis[to]&&ww<f[to]){
				f[to]=ww;
				q.push({ww,to});
			}
		}
	}
	if(k<n) cout<<"orz";
	else cout<<sum;
	return 0;
}