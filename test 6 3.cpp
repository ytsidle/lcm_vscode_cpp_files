#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+100;
//0,1背包
/*
	把捆绑起来的当成一个商品
	背包容量为钱
	花费为重量,价值=价值
*/
int n,m,w;
int a[MAX][3],dp[MAX],u,v,tmp,tmp1,add[MAX][3];
int main(){
	cin>>n>>m>>w;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i][1],&a[i][2]);
	}
	for(int i=1;i<=m;i++){
		cin>>add[i][1]>>add[i][2];
		tmp=add[i][1];
		tmp1=add[i][2];
		for(int j=1;j<=i;j++){
			if(add[j][1]==add[i][1]){
				a[add[j][2]][1]+=a[add[i][1]][1];
				a[add[j][2]][2]+=a[add[i][1]][2];
			}
			if(add[j][2]==add[i][1]){
				a[add[j][1]][1]+=a[add[i][1]][1];
				a[add[j][1]][2]+=a[add[i][1]][2];
			}
			//--------------------------------------------//
			if(add[j][1]==add[i][2]){
				a[add[j][2]][1]+=a[add[i][2]][1];
				a[add[j][2]][2]+=a[add[i][2]][2];
			}
			if(add[j][2]==add[i][2]){
				a[add[j][1]][1]+=a[add[i][2]][1];
				a[add[j][1]][2]+=a[add[i][2]][2];
			}
		}
		a[add[i][1]][1]+=a[add[i][2]][1];
		a[add[i][1]][2]+=a[add[i][2]][2];
		a[add[i][2]][1]+=tmp;
		a[add[i][2]][2]+=tmp1;
//		delete &tmp;
//		delete &tmp1;
	}
	//背包正式开始
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<a[i][1]<<" "<<a[i][2]<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=w;j>=1;j--){
			if(j>=a[i][1]) dp[j]=max(max(a[i][2],dp[j]),a[i][2]+dp[j-a[i][1]]);
			else dp[j]=dp[j];
		}
	}
	cout<<dp[w];
	return 0;
}
