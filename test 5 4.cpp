#include <bits/stdc++.h>
using namespace std;
const int MAX=1e4+10;
int n,m,dp[MAX][MAX],a[MAX];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	//Let's code together
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i==1 || j==1) dp[i][j]=a[j];
			else dp[i][j]=max(max(max(dp[i-1][j],dp[i][j-1]),a[j]),a[j]+dp[i][j-1]);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cout<<setw(5)<<dp[i][j];
		}cout<<endl;
	}
	cout<<dp[m][n];
	return 0;
}
