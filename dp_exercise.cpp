#include <bits/stdc++.h>
using namespace std;
const int MAX=1e4+100;
int n,a[MAX],dp[MAX],ma=-1;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}dp[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			if(dp[j]+1>dp[i]&&a[j]>=a[i]){
				dp[i]=dp[j]+1;
			}
		}if(dp[i]==0) dp[i]=1;
		ma=max(ma,dp[i]);
	}
	
	cout<<ma;
	return 0;
}
