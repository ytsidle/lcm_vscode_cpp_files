#include <bits/stdc++.h>
using namespace std;
const int  N=5050;
#define ll long long 
#define ld long double
ll x[N],y[N],n;
ld d[N],ans;
ll vis[N];
ld dist(ll i,ll j){
	return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n ;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		d[i]=LDBL_MAX;
	}
	d[0]=LDBL_MAX;
//	cout<<d[0];
	d[1]=0;
	for(int i=1;i<=n;i++){
		int u=0;
		for(int j=1;j<=n;j++){
			if(d[j]<d[u]&&!vis[j]) u=j;
		}
		vis[u]=1;
		ans+=d[u];
		for(int j=1;j<=n;j++){
			d[j]=min(d[j],dist(u,j));
		}
	}
	cout<<std::fixed<<setprecision(2)<<ans;
//	cout<<ans;
	return 0;
}