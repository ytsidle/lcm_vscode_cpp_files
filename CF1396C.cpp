#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int dp[N],n,ra,rb,rc,d,a[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>ra>>rb>>rc>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //dp[i] 表示1~i个关卡
    dp[0]=-d;
    dp[1]=min({a[1]*ra+rc,2*d+rb+ra,(a[1]+2)*ra+2*d});
    for(int i=2;i<=n;i++){
        dp[i]=min(dp[i-1]+d+a[i]*ra+rc,dp[i-1]+3*d+min(rb+ra,(a[i]+2)*ra));
        dp[i]=min(dp[i],dp[i-2]+d+min(rb+ra,(a[i-1]+2)*ra)+3*d+min(rb+ra,(a[i]+2)*ra));
        
    }
    // cout<<dp[n]<<endl;
    cout<<min(dp[n],dp[n-2]+3*d+rb+ra+a[n]*ra+rc)<<endl;
    return 0;
}