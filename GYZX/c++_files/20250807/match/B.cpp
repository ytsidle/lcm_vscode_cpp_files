#include <bits/stdc++.h>
using namespace std;
#define ll long long  
//#define sum(l,r) (t[min(n,r)]-t[l-1]);

const ll N=1e5+10;
ll n,a[N],l=1,r=1,t[N],z[N],m;
inline ll sum(ll l,ll r){
	return t[min(n,r)]-t[l-1];
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[i]=t[i-1]+a[i];
	}
	for(int i=n;i>=1;i--){
		if(a[i]==0) z[i]=z[i+1]+1;
	}
	ll ans=0;
	while(l<=n){
		if(sum(l,r)==m) ans+=z[r+1]+1,l++;
		else if(sum(l,r)<m&&r<n) r++;
		else l++;
	}
	cout<<ans;
	return 0;
}