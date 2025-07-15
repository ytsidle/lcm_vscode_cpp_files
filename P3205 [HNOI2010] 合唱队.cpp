#include <bits/stdc++.h>
using namespace std;
//P3205 [HNOI2010] 合唱队
int n,dp[2010][2010][2],h[2010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin>>h[i];
    for(int i=1;i<=n;i++){
        dp[i][i][0] = 1;
    }
    for(int len=1;len<=n;len++){
        for(int i=1,j=i+len;j<=n;i++,j++){
            if(h[i]<h[i+1])dp[i][j][0]+= dp[i+1][j][0];
            if(h[i]<h[j])  dp[i][j][0]+= dp[i+1][j][1];
            if(h[j]>h[j-1])dp[i][j][1]+= dp[i][j-1][1];
            if(h[j]>h[i])  dp[i][j][1]+= dp[i][j-1][0];
            dp[i][j][0]%=19650827;
            dp[i][j][1]%=19650827;
        }
    }
    cout<<((dp[1][n][0]+dp[1][n][1]))%19650827 << endl;
    return 0;
}