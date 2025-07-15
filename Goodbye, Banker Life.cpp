#include <bits/stdc++.h>
using namespace std;
//卡常输入
/*
Time limit3000 ms
Mem limit:262144 kB= GB
*/
#define ll int
const int M=1e3+10;
inline ll read(){
    ll x = 0, f = 1; 
    char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 1) + (x << 3) + ch - '0'; ch = getchar(); }
    return x * f;
}
inline void write(ll x){
    if (x < 0) { putchar('-'); x = -x; }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
ll t,n,k,dp[M][M];
ll dfs(int i,int j){
    if(i<M&&j<M&&dp[i][j])return dp[i][j];
    else if(i==j&&j==1) return k;
    else if(1<j&&j<i) return dfs(i-1,j-1)^dfs(i-1,j);
    else if(j==1) return k;
    else if(j==i) return k;
    else return 0;
}
int main(){
    t=read();
    while(t--){
        n=read();k=read();
        memset(dp,0,sizeof(dp));
        dp[1][1]=k;
        for(int i=1;i<=n;i++){
            write(dfs(n,i));
            putchar(' ');
        }putchar('\n');
    }

    return 0;
}