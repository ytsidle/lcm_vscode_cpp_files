#include <bits/stdc++.h>
using namespace std;
int n,m,dp[1010][1010],c[1010],kl[1010],w[1100];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		cin>>kl[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=j;k++){
				dp[i][j]=max(dp[i-1][j]*1.0,dp[i-1][j-k]+(min(1.0,k*1.0/kl[i])*100*c[i]));
			}
			
		}
	}
	printf("%.4f",dp[n][m]);
	return 0;
}
