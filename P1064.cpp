#include <bits/stdc++.h>
using namespace std;
const int MAX=1e4+20;
int n,m;
int dp[65][MAX],v[65],w[65],q,c[MAX][MAX],ndp[MAX];//ndp代表一维
int main() {
    scanf("%d%d",&n,&m);
    n/=10;
    for(int i=1;i<=m;i++) {
        scanf("%d%d%d",&v[i],&w[i],&q);
        v[i]/=10;
        c[q][0]++;
        c[q][c[q][0]]=i;

        w[i]*=v[i];
    }
    for(int i=1;i<=c[0][0];i++){
        for(int j=0;j<=n;j++){
            if(j<v[c[0][i]]) dp[i][j]=dp[i-1][j];
            else{
                int num2=(j-v[c[0][i]]>=0)?dp[i-1][j-v[c[0][i]]]+w[c[0][i]]:0;//只选主件
                int num3=(j-v[c[0][i]]-v[c[c[0][i]][1]]>=0)?dp[i-1][j-v[c[0][i]]-v[c[c[0][i]][1]]]+w[c[0][i]]+w[c[c[0][i]][1]]:0;//选主件和附件1
                int num4=(j-v[c[0][i]]-v[c[c[0][i]][2]]>=0)?dp[i-1][j-v[c[0][i]]-v[c[c[0][i]][2]]]+w[c[0][i]]+w[c[c[0][i]][2]]:0;//选主件和附件2
                int num5=(j-v[c[0][i]]-v[c[c[0][i]][1]]-v[c[c[0][i]][2]]>=0)?dp[i-1][j-v[c[0][i]]-v[c[c[0][i]][1]]-v[c[c[0][i]][2]]]+w[c[0][i]]+w[c[c[0][i]][1]]+w[c[c[0][i]][2]]:0;//选主件和附件1和附件2
                dp[i][j]=max(dp[i-1][j],max(num2,max(num3,max(num4,num5))));
            }
        }
    }
    printf("%d",dp[c[0][0]][n]*10);
    return 0;
}