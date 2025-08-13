#include <bits/stdc++.h>
using namespace std;
const int N=(1<<20)+5;
const int M=25,INF=2e9;
int dp[M][N],a[M][M],n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>a[i][j];
    }
    int lim=(1<<n)-1;
    for(int i=0;i<n;i++) fill(dp[i],dp[i]+lim+1,INF);
    // memset(dp,0x3f,sizeof(dp));
    dp[0][1]=0;
    for(int i=0;i<lim;i++){
        for(int j=0;j<n;j++){
            if(!((i>>j)&1)){
                continue;
            }
            for(int k=0;k<n;k++){
                if((i>>k)&1)continue;
                int tot=i|(1<<k);
                dp[k][tot]=min(dp[k][tot],dp[j][i]+a[j][k]);
            }
        }
    }
    cout<<dp[n-1][lim];
    return 0;
}