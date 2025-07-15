#include <bits/stdc++.h>
using namespace std;
int  dp[320][320],n,m[320],c[320];
int  dfs(int l,int r){
	if(l==r){
		return 0;
	}
	if(dp[l][r]!=0x3f3f3f3f)return dp[l][r];
	for(int i=l;i<r;i++){
		dp[l][r]=min(dp[l][r],dfs(l,i)+dfs(i+1,r)+c[r]-c[l-1]);
	}return dp[l][r];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m[i];
        c[i]=c[i-1]+m[i];
    }
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++){
    	dp[i][i]=0;
	}
	cout<<dfs(1,n);
    return 0;
}