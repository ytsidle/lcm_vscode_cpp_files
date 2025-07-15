#include <bits/stdc++.h>
using namespace std;
long long dp[110][110],n,m[110],c[110];
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
    for(int i=1;i<=n;i++){
        //枚举len
        for(int l=1;l+i-1<=n;l++){
            int r=l+i-1;
            //枚举k
//            dp[l][r]=LONG_LONG_MAX;
            for(int k=l;k<r;k++){
                dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]+c[r]-c[l-1]);
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}