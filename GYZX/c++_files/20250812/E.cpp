/*
Problem: P1896 互不侵犯
From: https://www.luogu.com.cn/problem/P1896
Author: Lai_Chengming
Date: 2025/08/12
*/
/*
这题dp定义是：dp[i][j][s]表示前i行放置j个棋子，且第i行的状态为s的方案数
状态压缩DP解决
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M=(1<<9)+10,N=15;
int n,kk,dp[N][90][M];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>kk;
    int lim=(1<<n)-1;
    dp[0][0][0]=1; //初始状态
    for(int i=1;i<=n;i++){
        //枚举层
        for(int tot=0;tot<=kk;tot++){
            for(int j=0;j<=lim;j++){
                for(int k=0;k<=lim;k++){
                    if(((k<<1)&j)|(k&j)|((k>>1)&j)) continue; //当前行状态与上一行不能有在攻击范围的棋子
                    if(((k<<1)&k)|(k&(k>>1))) continue;
                    if((tot-__builtin_popcount(k))>=0)dp[i][tot][k] += dp[i-1][tot-__builtin_popcount(k)][j]; 
                }
            }            
        }
    }
    int ans=0;
    for(int i=0;i<=lim;i++){
        ans+= dp[n][kk][i]; //统计所有放置k个棋子的方案数
    }
    cout<<ans;
    return 0;
}