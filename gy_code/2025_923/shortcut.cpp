#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,x[N],y[N];
inline long double pows(int num){
	return num*num*1.0;
}
inline long double dist(int x,int y,int a,int b){
	return sqrt(pows(x-a)+pows(y-b));
}
long double dp[N][30];//
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=28;j>=0;j--) dp[i][j]=DBL_MAX;
	}
	dp[1][0]=0;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=28;j++){
			dp[i][j]=min(dp[i][j],dp[i-1][j]+dist(x[i-1],y[i-1],x[i],y[i]));
			for(int k=1;k<i;k++){
				if(k+j+1>i) continue;
				if(j&&i!=n){
					dp[i][j]=min(dp[i][j],dp[k][j-(i-k-1)]+dist(x[k],y[k],x[i],y[i]));
				}
			}
		}
	}
	long double ans=LDBL_MAX;
	for(int j=0;j<=28;j++){
		ans=min(ans,dp[n][j]+pow(2,j-1));;
		cout<<(dp[n][j]+pow(2,j-1))<<" ";
	}cout<<setprecision(26)<<ans;
	return 0;
}
