#include <bits/stdc++.h>
using namespace std;
const int M=(1<<22)+10,mod=1e8;
int n,m,g[24],cnt,s[M],dp[24][M];
inline void add(int &x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}
int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        for(int j=1;j<=m;j++){
           cin>>x;
           g[i] =(g[i]<<1)|x;
        }
        // cout<<g[i]<<"\n";
    }
    int lim=(1<<m)-1;
    // cout<<lim<<"\n";
    for(int i=0;i<=lim;i++){
        if(i&(i<<1)) continue;
        s[++cnt]=i;
        // cout<<s[cnt]<<'\n';
    }
    dp[0][1]=1;
    // for(int i=1;i<=cnt;i++) if((s[i]&g[1])!=s[i]) dp[1][i]=1;
    for(int i=1;i<=n;i++){
        //枚举层
        for(int j=1;j<=cnt;j++){
            
            if(!dp[i-1][j])         continue;
            if((g[i-1]&s[j])!=s[j]) continue;
            // cout<<i<<" "<<j<<" "<<"\n";
            for(int k=1;k<=cnt;k++){
                if(s[j]&s[k])         continue;
                if((g[i]&s[k])!=s[k]) continue;
                // cout<<i<<" "<<j<<" "<<k<<"\n";
                // dp[i][k]+=dp[i-1][j];
                add(dp[i][k], dp[i-1][j]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=cnt;i++){
        add(ans, dp[n][i]);
    }
    cout<<ans;
    return 0;
}