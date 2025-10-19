#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,dp[5050][5050][2];
struct Data{
	int  a,b;
	bool operator<(const Data& an) const {
		return a<an.a;
	}
}d[5050];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>d[i].a;
	}
	for(int i=1;i<=n;i++){
		cin>>d[i].b;
	}
	sort(d+1,d+1+n);
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=d[n].a;j++){
			dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j][1])%mod;
			if(j>=d[i].b){
				dp[i][j][1]=(dp[i-1][j-d[i].b][0]+dp[i-1][j-d[i].b][1])%mod;
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=d[i].a;j++){
			ans+=dp[i][j][1];
			ans%=mod;
		}
	}cout<<ans;
	return 0;
}
