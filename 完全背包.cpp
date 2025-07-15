#include <bits/stdc++.h>
#define itn int
#define scnaf scanf//防打错
using namespace std;
const int MAX=1e7+10;
long long m,t,tme,v,dp[MAX];
int main(){
	scanf("%lld%lld",&t,&m);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld",&tme,&v);
		for(int j=tme;j<=t;j++){
			dp[j]=max(dp[j],dp[j-tme]+v);
		}
	}
	printf("%lld",dp[t]);
	return 0;
}
