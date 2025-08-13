#include <bits/stdc++.h>
/*
problem: P2704 [NOI2001] 炮兵阵地
site : https://www.luogu.com.cn/problem/P2704
author: laichenming
*/
using namespace std;
const int INF = -1e9;
int n,m,g[105],f[105][105][105],s[105],cnt;
char c;
inline bool is(int i,int j){
    return (g[i]&s[j])==s[j];
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            cin>>c;
            g[i]+= (1 << j)*(c=='P');
        }
    }
    int lim=(1<<m)-1;
    for(int i=0;i<=lim;i++){
        if(((i<<2)&i)|((i<<1)&i) || ((i>>1)&i) || ((i>>2)&i)) continue;
        s[++cnt]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=cnt;j++){
            for(int k=1;k<=cnt;k++){
                f[i][j][k] = INF;
            }
        }
    }
    for(int i-1;i<=cnt;i++){
        if(is(1,i)){
            //可以放置
            f[1][i][__builtin_popcount(s[i])];
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=)
    }
    return 0;
}