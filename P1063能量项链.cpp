#include <bits/stdc++.h>
using namespace std;

int dp[300][300],n,h[300],t[300],INF;
int dfs(int l,int r){
	if(l==r) return 0;
	if(dp[l][r]!=INF) return dp[l][r];
	for(int k=l;k<r;k++){
		dp[l][r]=max(dp[l][r],dfs(l,k)+dfs(k+1,r)+h[l]*t[k]*t[r]);
	}return dp[l][r];
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>h[i];
		h[i+n]=h[i];
	}for(int i=1;i<=2*n-1;i++) t[i]=h[i+1];
	t[2*n]=h[1];
	memset(dp,0x80,sizeof(dp));
	INF=dp[0][0];
//	cout<<INF<<endl;
	int ans=0;
	for(int i=1;i+n-1<=2*n;i++){
		ans=max(dfs(i,i+n-1),ans);
	}
	cout<<ans;
	return 0;
}
