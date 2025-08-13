#include <bits/stdc++.h>
using namespace std;
#define answer return
#define accept 0;
const int N = 3e5+10;
char s[N];
long long n,dp[3][N],x,y,z;
int main(){
	scanf("%lld%lld%lld",&x,&y,&z);
	scanf("%s",s+1);
	n=strlen(s+1);
//	cout<<n;
	dp[2][0]=z;
	for(int i=1;i<=n;i++){
		if(s[i]=='a'){
			//小写
			dp[1][i]=dp[1][i-1]+x;//关的
//			dp[1][i]=min(dp[1][i],dp[2][i-1]+y);
			dp[1][i]=min({dp[1][i],dp[2][i-1]+z+x,dp[2][i-1]+y+z});
			dp[2][i]=dp[2][i-1]+y;
			dp[2][i]=min({dp[2][i],dp[1][i-1]+x+z,dp[1][i-1]+z+y});
		}else{
			dp[2][i]=dp[2][i-1]+x;
			dp[2][i]=min({dp[2][i],dp[1][i-1]+y+z,dp[1][i-1]+z+x});
			dp[1][i]=dp[1][i-1]+y;
			dp[1][i]=min({dp[1][i],dp[2][i-1]+x+z,dp[2][i-1]+z+y});
		}
	}cout<<min(dp[1][n],dp[2][n]);
	answer accept
}