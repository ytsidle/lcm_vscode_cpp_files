#include<bits/stdc++.h>
// #pragma GCC optimize(3)
using namespace std;
//合并饭团 区间DP
inline int read() {
    register int x = 0, f = 1;
    register char ch;
    while(!isdigit(ch = getchar())) (ch == '-') && (f = -1);
    for(x = ch ^ 48; isdigit(ch = getchar()); x = (x << 3) + (x << 1) + (ch ^ 48));
    return x * f;
}

int dp[500][500],n,s[500],ans=0,sum[500];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    n = read();
    for(int i = 1; i <= n; i++) {
        s[i] = read();
        sum[i] = sum[i-1] + s[i];
        ans=max(ans, s[i]);
        dp[i][i] = s[i];
    }
    
    for(int len=1;len<=n;len++){
        for(int l=1;l+len<=n;l++){
            int r=l+len;
            for(int k=l;k<r;k++){
                if(dp[l][k]==dp[k+1][r]&&dp[l][k]!=-1) {
                    dp[l][r] = max(dp[l][r],dp[l][k] + dp[k+1][r]);
                    break;
                }
            }
            for(int k=l;k<r;k++){
                for(int k1=r;k1-1>k;k1--){
                    if(dp[k + 1][k1 - 1] != -1 && dp[k1][r]!=-1 && dp[l][k] == dp[k1][r] ) {
                        dp[l][r] = max(dp[l][r], dp[l][k] + dp[k+1][k1-1] + dp[k1][r]);
                        break;
                    }
                }
            }ans = max(ans, dp[l][r]);
        }
    }cout<<ans;
    #ifndef ONLINE_JUDGE
        getchar();
    #endif
    return 0;
}