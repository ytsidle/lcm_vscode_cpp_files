#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bi ((j-i-1)/2)
int n,k,dp[3050][110],tmp[3050],a[3050];
inline int val(int i,int j){
    return a[j]*a[j]+((j-i)*(j-i-1)/2)*max(a[i],a[j]);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    int zp=0;
    for(int i=1;i<=n;i++){
        cin>>tmp[i];
        if(tmp[i]==0) zp=i;
    }
    int cnt=0;
    for(int i=zp;i<=n;i++){
        a[++cnt]=tmp[i];
    }
    for(int i=1;i<zp;i++){
        a[++cnt]=tmp[i];
    }
    // for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    // cout<<"\n";
    memset(dp,0x3f,sizeof(dp));
    dp[1][1]=0;//dp[i][m]表示在激活i的情况下，前i个至少激活m个的答案最小值(实际上只有在m==k才是正确否则是刚好)
    for(int i=2;i<=n;i++){
        for(int m=2;m<=min(i,k);m++){
            for(int j=1;j<i;j++){
                int ttmp=val(j,i);
                dp[i][m]=min(dp[i][m],dp[j][m-1]+ttmp);
                dp[i][m]=min(dp[i][m],dp[j][m]+ttmp);
                //为什么可以加上一个 $if(m==k)$在第二行前
            }
        }
    }
    int ans=INT_MAX;
    for(int i=1;i<=n;i++) ans=min(ans,dp[i][k]+val(i,n+1));
    cout<<ans;
    return 0;
}