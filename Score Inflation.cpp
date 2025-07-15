#include <bits/stdc++.h>
using namespace std;
const int MAX=1e4+10;
int m,n,p,t,dp[MAX];//m表时间
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p,&t);
		for(int j=t;j<=m;j++){
			dp[j]=max(dp[j],dp[j-t]+p);	
		}
	}printf("%d",dp[m]);
	return 0;
}
