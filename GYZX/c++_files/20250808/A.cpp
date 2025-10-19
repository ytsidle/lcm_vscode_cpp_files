#include <bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
const int M=1e6+10;
long long n,m,dp[M][3];
//WA
int main(){
	cin>>n>>m;
	dp[1][1]=m;//跟头一样
//	dp[1][2]=0;//与头不同
	for(int i=2;i<=n;i++){
		dp[i][2]=(dp[i-1][1]*(m-1)%MOD+dp[i-1][2]*(m-2)%MOD)%MOD;
		dp[i][1]=dp[i-1][2];
	}cout<<dp[n][2]%MOD;
	return 0;
}