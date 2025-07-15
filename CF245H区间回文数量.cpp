#include<bits/stdc++.h>
// 题目: CF245H 区间回文数量
// 题目链接: https://codeforces.com/problemset/problem/245/H
//time limit :2S
using namespace std;
// #define int long long
char s[5050];
int pa[5050][5050],dp[5050][5050],n,q;
int check(int l,int r){
    if(l>r) return 1;
    if(l==r) return 1;
    return pa[l][r];
}
signed main(){
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for(int i=1;i<=n;i++) dp[i][i]=pa[i][i]=1;
    for(int i=1;i<n;i++) dp[i][i+1]=(s[i]==s[i+1]?3:2);
    scanf("%d", &q);
    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            pa[l][r]=(s[l]==s[r] && check(l+1,r-1));
        }
    }
        for(int len=2;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            dp[l][r]=(dp[l+1][r] + dp[l][r-1] - dp[l+1][r-1] + pa[l][r]);
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         printf("%lld ", dp[i][j]);
    //     }printf("\n");
    // }
    // cout<<"------------\n";
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         printf("%lld ", pa[i][j]);
    //     }printf("\n");
    // }
    while(q--){
        int l,r;
        scanf("%d %d", &l, &r);
        printf("%d\n",dp[l][r]);
    }
    return 0;
}