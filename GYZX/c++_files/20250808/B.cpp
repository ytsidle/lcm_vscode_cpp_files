#include <bits/stdc++.h>
#define int long long
#define ll long long 
using namespace std;
using pll=pair<ll,ll>;
const ll N=3e5+10;
ll n,x[N],dp[N],a[N];
priority_queue<pll> q0,q1;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>a[i];
		
		if(x[i]==0){
			int qt=0,qt2=0;
			if(!q0.empty()) qt=q0.top().second;
			if(!q1.empty()) qt2=q1.top().second;
			if(dp[qt]>dp[qt2]&&q0.size()&&a[i]>=0){
				q0.pop();
			}else if(q1.size()&&a[i]>=0){
				q1.pop();
			}
			dp[i]=max(dp[i],max(dp[qt],dp[qt2])+a[i]);
			q0.push({dp[i],i});
		}else{
			int qt=0;
			if(!q0.empty()){
				qt=q0.top().second;
				q0.pop();
			}
			dp[i]=max(dp[i],dp[qt]+a[i]);
			q1.push({dp[i],i});
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}