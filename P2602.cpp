#include<bits/stdc++.h>
using namespace std;
#define int long long

/*
求出dp[i][j][k]表示i位首位是j,考虑第k这个数截至目前总出现次数
=10^(i-1)*(j==k)+dp[i-1][0~9][k]

分段
*/
int dp[15][10][10],aa,b,pw[20],a[20];
int solve(int x,int num){
    //位数<x
    int cnt = 0;
    while (x) { // 分解数位
        a[++cnt] = x % 10;
        x /= 10;
    }
    int ans=0;
    for(int i=1;i<cnt;i++){
        for(int j=1;j<=9;j++){
            ans+=dp[i][j][num];
        }
    }
    //位数==x
    for(int i=cnt;i;i--){
        if(cnt==i){
            for(int j=1;j<a[i];j++)ans+=dp[i][j][num];
        }else{
            for(int j=cnt;j>i;j--){
                if(a[j]==num) ans+=pw[i-1]*a[i];
            }
            for(int j=0;j<a[i];j++) ans+=dp[i][j][num];
        }
    }
    return ans;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>aa>>b;
    int t=1;
    pw[0]=1;
    for(int i=1;i<=15;i++){
        t*=10;
        pw[i]=t;
    }
    for(int i=0;i<=9;i++) dp[1][i][i]=1;
    for(int i=2;i<=13;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                for(int d=0;d<=9;d++){
                    dp[i][j][k]+=dp[i-1][d][k];
                }
            }
            dp[i][j][j]+=pw[i-1];
        }
    }
    for(int i=0;i<=9;i++)
    cout<<solve(b+1,i)-solve(aa,i)<<" ";
    return 0;
}