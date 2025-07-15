#include <bits/stdc++.h>
using namespace std;
const int MAX=1e4+20;
int n,m;
int dp[MAX],v[65],w[65],q,c[MAX][MAX];
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
        //滚动优化
        for(int j=n;j>=v[c[0][i]];j--){
            int v2=(j-v[c[0][i]]>=0)?dp[j-v[c[0][i]]]+w[c[0][i]]:0;//只选主件
            int v3=(j-v[c[0][i]]-v[c[c[0][i]][1]]>=0)?dp[j-v[c[0][i]]-v[c[c[0][i]][1]]]+w[c[0][i]]+w[c[c[0][i]][1]]:0;//选主件和附件1
            int v4=(j-v[c[0][i]]-v[c[c[0][i]][2]]>=0)?dp[j-v[c[0][i]]-v[c[c[0][i]][2]]]+w[c[0][i]]+w[c[c[0][i]][2]]:0;//选主件和附件2
            int v5=(j-v[c[0][i]]-v[c[c[0][i]][1]]-v[c[c[0][i]][2]]>=0)?dp[j-v[c[0][i]]-v[c[c[0][i]][1]]-v[c[c[0][i]][2]]]+w[c[0][i]]+w[c[c[0][i]][1]]+w[c[c[0][i]][2]]:0;//选主件和附件1和附件2
            dp[j]=max(dp[j],max(v2,max(v3,max(v4,v5))));
        }
    }
    printf("%d",dp[n]*10);
    return 0;
}