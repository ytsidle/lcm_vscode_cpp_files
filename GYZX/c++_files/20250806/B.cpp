#include <bits/stdc++.h>
using namespace std;
char s[4000],s2[4000],ans[4000];
int dp[4000][4000],x[4000][4000],y[4000][4000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    scanf("%s",s+1);
    scanf("%s",s2+1);
    int n = strlen(s+1), m = strlen(s2+1);
    // cout<<n<<" "<<m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i]==s2[j]){
                dp[i][j]=dp[i-1][j-1]+1;
                x[i][j]=y[i][j]=1;
            }else if(dp[i][j-1]<dp[i-1][j]){
                //x表示转移自dp[i-1][j]
                dp[i][j]=dp[i-1][j];
                x[i][j]=1;
            }else{
                //y表示转移自dp[i][j-1]
                dp[i][j]=dp[i][j-1];
                y[i][j]=1;
            }
        }
    }
   // cout<<dp[n][m]<<"\n";
    int i=n,j=m,cnt=0;
    
    while(x[i][j]||y[i][j]){
        if(x[i][j]&&y[i][j]==0){
            i=i-1;
        }else if(y[i][j]&&x[i][j]==0){
            j=j-1;
        }else{
            ans[++cnt]=s[i];
            i=i-1,j=j-1;
        }
    }
    for(int k=cnt;k>=1;k--){
        cout<<(ans[k]);
    }
    return 0;
}