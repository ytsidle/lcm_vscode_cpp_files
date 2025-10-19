#include <bits/stdc++.h>
#define ll long long 
using namespace std;
using pll=pair<ll,ll>;
const ll N=3e5+10;
ll dp[N][3],a[N],x[N],n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	memset(dp,0x80,sizeof(dp));
	dp[0][1]=dp[0][2]=0;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>a[i];
		dp[i][1]=dp[i-1][1],dp[i][2]=dp[i-1][2];
		if(x[i]==0){
			dp[i][1]=max({dp[i][1],dp[i-1][2]+a[i],dp[i-1][1]+a[i]});
		}else{
			dp[i][2]=max({dp[i][2],dp[i-1][1]+a[i]});
		}
	}
	cout<<max({0ll,dp[n][1],dp[n][2]});
	return 0;
}