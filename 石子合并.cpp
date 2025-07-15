#include <bits/stdc++.h>
using namespace std;
int dp[310][310],n,a[310],b[310],dp2[310][310];
inline int cost(int l,int r){
	return b[r]-b[l-1];
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i*2]=a[i];
		b[i]=b[i-1]+a[i];
	} 
	for(int i=n+1;i<=2*n;i++) b[i]=b[i-1]+a[i];
	int num=n;
	n*=2;
	for(int len=2;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			dp[l][r]=INT_MAX;
			dp2[l][r]=INT_MIN;
			for(int k=l;k<=r;k++){
				dp[l][r]=min(dp[l][r],dp[l][k-1]+dp[k][r]+cost(l,r));
				dp2[l][r]=max(dp[l][r],dp[l][k-1]+dp[k][r]+cost(l,r));
			}
		}
	}
	int dpa=INT_MAX,dpb=INT_MIN;
	for(int i=1;i<=num;i++){
		dpa=min(dpa,dp[i][i+num-1]);
		dpb=max(dpb,dp2[i][i+num-1]);
	}
	cout<<dpa<<endl<<dpb;
	return 0;
}
