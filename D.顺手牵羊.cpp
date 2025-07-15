#include <bits/stdc++.h>
using namespace std;
int a[1005][1005],dp[1005][1005],n,k;
bool check(int num){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			bool now=(a[i][j]>=num);
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])+now;
		}
	}
	return dp[n][n]>=k;
}
int main(){
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	//右边界
	int l=1;
	int r=1000000000;
	int ans;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else 
			r=mid-1;
	}cout<<ans;
	return 0;
}
