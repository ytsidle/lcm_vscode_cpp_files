#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int dp[MAX][2],n,d,v[MAX],a[MAX];//dp[i][0]表示🚗开到第i个站时,花的最少钱数,dp[i][1]表示前面的站中油费最便宜的站
long long hlong(int f,int e){
	if(f==e){
		return 0;
	}else{
		long long ans=0;
		for(int i=f;i<e;i++){
			ans+=v[i];
		}return ans;
	}
}
int hol(long long len){
	if(len%d!=0){
		return len*1.0/d/1+1;
	}else return len/d;
}
int main(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<n;i++){
		scanf("%d",&v[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dp[0][1]=0;
	a[0]=INT_MAX;
	dp[1][0]=0;
	dp[1][1]=0;
	for(int i=2;i<=n;i++){
		dp[i-1][1]=a[i-1]<a[dp[i-2][1]] ? i-1:dp[i-2][1];
		dp[i][0]=hol(hlong(dp[i-1][1],i-1))*a[i-1]+dp[dp[i-1][1]][0];
	}
	for(int i=1;i<=n;i++){
		cout<<dp[i][0]<<" ";
	}
	printf("\n%d",dp[n][0]);
//	cout<<hol(10);
	return 0;
}
