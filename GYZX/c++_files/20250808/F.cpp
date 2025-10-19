#include <bits/stdc++.h>
using namespace std;
int	dp[42][42][42][42],n,c[400],s[400],m,t[400];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=m;i++) {
		cin>>c[i];
		t[c[i]]++;
	}
	//dp[i][a][b][c][d]
	for(int a=0;a<=t[1];a++){
		for(int b=0;b<=t[2];b++){
			for(int c=0;c<=t[3];c++){
				for(int d=0;d<=t[4];d++){
					int p=a+2*b+3*c+4*d+1;
					if(a) dp[a][b][c][d]=max(dp[a][b][c][d],dp[a-1][b][c][d]);
					if(b) dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b-1][c][d]);
					if(c) dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b][c-1][d]);
					if(d) dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b][c][d-1]);
					dp[a][b][c][d]+=s[p];
				}
			}
		}
	}
	cout<<dp[t[1]][t[2]][t[3]][t[4]];
	return 0;
}