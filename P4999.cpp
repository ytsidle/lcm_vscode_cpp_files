#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;

int dp[25][10],l,r,pw[25],a[25],T;
int solve(int x){
    //位数<x
    int cnt = 0;
    while (x) { // 分解数位
        a[++cnt] = x % 10;
        x /= 10;
    }
    int ans=0;
    for(int i=1;i<cnt;i++){
        for(int j=1;j<=9;j++) {
            ans+=dp[i][j];
            ans%=mod;
        }
    }
    //位数==x
    for(int i=cnt;i;i--){
        if(i==cnt){
            for(int j=1;j<a[i];j++){
                ans+=dp[i][j];
                ans%=mod;
            }
        }else{
            for(int j=0;j<a[i];j++){
                ans+=dp[i][j];
                ans%=mod;
            }
            for(int j=cnt;j>i;j--){
                ans+=a[j]*a[i]*pw[i-1]%mod;
                ans%=mod;
            }
        }
    }
    return ans;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    pw[0]=1;
    for(int i=1;i<=20;i++){
        pw[i]=pw[i-1]*10%mod;
    }
    for(int i=0;i<=9;i++) dp[1][i]=i;
    for(int i=2;i<=20;i++){
        for(int j=0;j<=9;j++){
            dp[i][j]=pw[i-1]*j%mod;
            for(int d=0;d<=9;d++){
                dp[i][j]+=dp[i-1][d];
                dp[i][j]%=mod;
            }
        }
    }
    cin>>T;
    while(T--){
        cin>>l>>r;
        cout<<(solve(r+1)-solve(l)+mod)%mod<<"\n";
    }
    return 0;
}