#include <bits/stdc++.h>
using namespace std;
char s[100];
int dp[100][100];
int main(){
    scanf("%s",s+1);
    // memset(dp,0x3f,sizeof(dp));
    int n=strlen(s+1);
    for(int i=1;i<=n;i++)dp[i][i]=1;
    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            if(s[l]==s[r]){
                //simple
                dp[l][r]=min(dp[l+1][r], dp[l][r-1]);
            }else{
                dp[l][r]=n;
                for(int i=l;i<r;i++){
                    //枚举中点
                    dp[l][r]=min(dp[l][r],dp[l][i]+dp[i+1][r]);
                }
            }
        }
    }
    cout<<dp[1][n];
    return 0;
}