#include <bits/stdc++.h>
using namespace std;
#define bi ((j-i-1)/2)
int n,k,dp[3050][110],tmp[3050],a[3050];
inline int val(int i,int j){
    if(a[i]==a[j]){
        if((j-i-1)%2==0){
            return ((1+bi)*bi+bi+1)*a[i]+a[j]*a[j];
        }
        else return (1+bi)*bi*a[i]+a[j]*a[j];
    }else{
        return a[j]*a[j]+((j-i)*(j-i-1)/2)*max(a[i],a[j]);
    }
}
int main(){
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
        a[++cnt]=tmp[zp];
    }
    for(int i=1;i<zp;i++){
        a[++cnt]=tmp[i];
    }

    memset(dp,0x3f,sizeof(dp));
    dp[1][1]=0;//dp[i][m]表示在激活i的情况下，前i个至少激活m个的答案最小值(实际上只有在m==k才是正确否则是刚好)
    for(int i=2;i<=n;i++){
        for(int m=2;m<=min(i,k);m++){
            for(int j=1;j<i;j++){
                dp[i][m]=min(dp[i][m],dp[j][m-1]+val(j,i));
                dp[i][m]=min(dp[i][m],dp[j][m]+val(j,i));
            }
        }
    }
    int ans=INT_MAX;
    for(int i=1;i<=n;i++) ans=min(ans,dp[i][k]);
    cout<<ans;
    return 0;
}