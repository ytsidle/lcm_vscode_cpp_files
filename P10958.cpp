#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,a[20],dp[20][20][2];
int dfs(int pos,int cnt,int flag,int limit){
    if(pos==0) return flag;
    if(limit==0&&dp[pos][cnt][flag]!=-1) return dp[pos][cnt][flag];
    int lim=limit?a[pos]:9;
    int res=0;
    for(int i=0;i<=lim;i++){
        int n=((i==6)?cnt+1:0);
        res+=dfs(pos-1,n,flag||(n>=3),limit&&(i==a[pos]));
    }
    if(limit==0) dp[pos][cnt][flag]=res;
    return res;
}
int solve(int x){
    //拆
    int cnt=0;
    while(x){
        a[++cnt]=x%10;
        x/=10;
    }
    return dfs(cnt,0,0,1);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    memset(dp,-1,sizeof dp);
    while(T--){
        int x;
        cin>>x;
        int l = 1, r = 1e10, ans = -1;
        while (l <= r) {    // 二分后dp
            int mid = (l + r) >> 1;
            if (solve(mid) >= x)
                r = mid - 1, ans = mid;
            else
                l = mid + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}