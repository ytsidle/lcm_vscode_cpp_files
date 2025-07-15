#include <bits/stdc++.h>
using namespace std;
const int MAX=2e4+10;
int maxw,dp[MAX],n,w,p;//w为重,p为价值
int main() {
    scanf("%d%d",&maxw,&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&w,&p);
        for(int j=maxw;j>=w;j--){
            dp[j]=max(dp[j],dp[j-w]+p);
        }
    }
    printf("%d",dp[maxw]);
    return 0;
}