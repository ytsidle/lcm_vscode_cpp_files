#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=12,M=(1<<12)+10,INF=2e9+14;
int h,w,dp[N][M],g[M];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>h>>w&&h&&w){
        int lim=(1<<(w))-1;
        //打表
        for(int i=0;i<=lim;i++){
            int cnt=0;
            g[i]=1;
            for(int j=0;j<w;j++){
                if((i>>j)&1){
                    if(cnt&1){
                        g[i]=0;
                        break;
                    }
                }
                else cnt++;
            }
            if(cnt&1){
                 g[i]=0;
            }
        }
        for(int i=0;i<=h;i++) fill(dp[i],dp[i]+lim+1,0);
        dp[0][0]=1;
        for(int i=1;i<=h;i++){
            for(int j=0;j<=lim;j++){
                //枚举上一层的所有状态
                if(!dp[i-1][j]) continue;//因为无贡献，浪费剪枝
                for(int k=0;k<=lim;k++){
                    if((g[k|j])&&(k&j)==0) 
                    dp[i][k]+=dp[i-1][j];
                }
            }
        }
        cout<<dp[h][0]<<"\n";
    }
    return 0;
}