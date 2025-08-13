#include <bits/stdc++.h>
using namespace std;
int n,k,dp[205][10];
int main(){
	cin>>n>>k;
	
	dp[1][1]=1;
	for(int i=1;i<=n;i++){
		dp[i][1]=1;
		for(int j=2;j<=k;j++)if(i>=j) dp[i][j]=dp[i-1][j-1]+dp[i-j][j];
	}
	cout<<dp[n][k];
	return 0;
}