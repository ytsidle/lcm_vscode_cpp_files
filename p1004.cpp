#include <bits/stdc++.h>
using namespace std;
int a[15][15],n,x,y,v,sum,dps[15][15];
void dela(){

}
void dfs(int &b[][],int &dp[][]){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int num=a[i][j];
			
			dp[i][j]=max(dp[i][j-1]+num,dp[i-1][j]+num);
//			if(dp[i][j-1]>dp[i-1][j]) a[i][j-1]=0;
//			else a[i-1][j]=0;
		}
	}

}
int main(){
	cin>>n;
	while(cin>>x>>y>>v){
		if(x!=0 && y!=0 && v!=0) a[x][y]=v;
		else break;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<setw(5)<<a[i][j];
//		}cout<<endl;
//	}
	dfs(a,dps);
	sum+=dps[n][n];
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<setw(5)<<dp[i][j];
//		}cout<<endl;
//	}
	dela();
	memset(dps,0,sizeof(dps));
	dfs(a,dps);
	
	sum+=dps[n][n];
	cout<<sum;

	return 0;
}
