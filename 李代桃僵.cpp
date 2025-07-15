#include <bits/stdc++.h>
using namespace std;
int dp[5600][6000],n,k,a[6000],b[6000],half;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	half=n/2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=half;i++){
		for(int j=0;j<=k;j++){
			dp[i][j]=dp[i-1][j];
			if(j>=1&&dp[i-1][j-1]!=-1){
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]+max(a[i], a[i + half]));
			}if(j>=2&&dp[i-1][j-2]!=-1){
				dp[i][j]=max(dp[i][j],dp[i-1][j-2]+b[i]+b[i+half]);
			}
		}
	}
	cout<<dp[half][k];
	return 0;
}
