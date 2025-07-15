#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+1490;
/*
题意:有 d 种债券，第 i 种需要 a的资产，会获得 b
 的成本。现在告诉你总资产以及债券的种类数，
 要你求 n 年后能有多少钱。
*/
int dp[MAX],s,n,d,a[15],b[15],z;
int main(){
	scanf("%d%d%d",&s,&n,&d);
	
	for(int i=1;i<=d;i++){
		scanf("%d%d",&a[i],&b[i]);
	}
	//重复年
	for(int i=1;i<=n;i++){//i is year
		z=s/1000;
		memset(dp,0,sizeof(dp));
		for(int j=1;j<=d;j++){
			if(a[j]/1000<=z){
				for(int k=a[j]/1000;k<=z;k++){
					dp[k]=max(dp[k],dp[k-a[j]/1000]+b[j]);
				}
			}
		}
//		for(int x=1;x<=z;x++){
//			cout<<dp[x]<<" ";
//		}cout<<endl;
		s+=dp[z];
	}printf("%d",s);
	return 0;
}
