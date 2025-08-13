#include <iostream>
// #define int long long
using namespace std;
const int N=(1<<22)+10;
int n,m,g[24],dp[24][N],x;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            cin>>x;
            g[i]=(g[i]<<1)|x;
        }
    }
    // for(int i=1;i<=n;i++) cout<<g[i]<<"\n";
    int lim=(1<<m)-1;
// cout<<lim;
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<lim;j++){
            if((g[i-1]&j)!=j) continue;//如果上一层枚举的不合法跳过
            if(j&(j<<1))      continue;
            if(!dp[i-1][j])   continue;//如果无额外价值浪费
            for(int k=0;k<=lim;k++){
                if((g[i]&k)!=k) continue;
                if(k&(k<<1))    continue;
                if(j&k)         continue;
                dp[i][k]+=dp[i-1][j];
                dp[i][k]%=(int)(1e8);
            }
        }
    }
    int ans=0;
    for(int i=0;i<=lim;i++){
        ans+=dp[n][i];
        ans%=(int)(1e8);
    }
    cout<<ans%(int)(1e8);
    return 0;
}