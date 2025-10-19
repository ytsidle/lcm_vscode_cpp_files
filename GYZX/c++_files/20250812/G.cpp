#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M=(1<<11)+5;
const int INF=2e9;
int n,m,a[105][15],dp[M],vis[M],f[M];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    // n--;
    int st=(1<<(n))-1;//表示n个灯全开的状态
    // cout<<__builtin_popcount(st)<<" "<<(bitset<10>(st))<<" "<<n<<"\n";
    fill(dp,dp+1+st,INF);//设不可到达为INF
    // memset(dp,0x3f,sizeof(dp));//测试，使用恶臭的memeset
    dp[st]=0;//默认全开是不用任何开关的
    //O(N^2)的dijkstra
    for(int i=0;i<=st;i++){
        int mi=-1;
        for(int j=0;j<=st;j++) {
            if(!vis[j]&&(mi==-1||dp[j]<dp[mi])) mi=j;
        }
        if(mi==-1||(dp[mi]==INF)) break;
        vis[mi]=1;
        for(int j=1;j<=m;j++){//枚举每条出边
            int tmp=mi;
            for(int k=0;k<n;k++){
                if(a[j][k]==1&&((mi>>k)&1)){
                    tmp^=(1<<k);//对第k位取反
                }if(a[j][k]==-1&&((mi>>k)&1)==0){
                    tmp|=(1<<k);
                }
            }
           
            if(dp[mi]+1<dp[tmp]) f[tmp]=mi;
            dp[tmp]=min(dp[tmp],dp[mi]+1);
        }
    }
    for(int i=0;i<=0;i++)
    cout<<((dp[i]>=INF)?-1:dp[i])<<"\n";
    return 0;
}