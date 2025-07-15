#include <bits/stdc++.h>
using namespace std;
long long dp[30][30],n,m,mx,my,d[30][30];
int fx[9]={0,-2,-2,-1,1,2,2,1,-1};
int fy[9]={0,-1,1,2,2,-1,1,-2,-2};
int main(){
	cin>>n>>m>>mx>>my;
	n++,m++,mx++,my++; 
	d[mx][my]=1;
	dp[1][1]=1;
	for(int i=1;i<=8;i++){
		int ti=mx+fy[i],tj=my+fx[i];
		if(ti>=1&&ti<=n&&tj>=1&&tj<=m){
			d[ti][tj]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(d[i][j]) continue;
			dp[i][j]+=dp[i-1][j]+dp[i][j-1];
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<setw(5)<<dp[i][j]; 
//		}cout<<endl;
//	}
	cout<<dp[n][m];
	return 0;
}
