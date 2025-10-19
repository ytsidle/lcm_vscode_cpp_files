#include <bits/stdc++.h>
using namespace std;
const int  N=2050;
//#define long long int
#define ll int 
#define ld int
ll x[N],y[N],n;
ld d[N],ans,c;
ll vis[N];
inline ld dist(ll i,ll j){
	return ((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> c;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		d[i]=INT_MAX;
	}
	d[0]=INT_MAX;
//	cout<<d[0];
	d[1]=0;
	for(int i=1;i<=n;i++){
		int u=0;
		for(int j=1;j<=n;j++){
			if(d[j]<d[u]&&!vis[j]) u=j;
		}
		if(u==0){
			cout<<-1;
			return 0;
		}
		vis[u]=1;
		ans+=d[u];
		for(int j=1;j<=n;j++){
			if(dist(u,j)>=c)
			d[j]=min(d[j],dist(u,j));
		}
	}
	cout<<ans;
//	cout<<ans;
	return 0;
}