#include <bits/stdc++.h>
using namespace std;
int dp[330][330],n,a[330],b[330];
inline int cost(int l,int r){
	return b[r]-b[l-1];
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	} 
	for(int len=2;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			dp[l][r]=INT_MAX;
			for(int k=l;k<=r;k++){
				dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]+cost(l,r));
			}
		}
	}
	cout<<dp[1][n];
	return 0;
}
