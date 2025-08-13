#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int ans[5050][5050],n,k;
int main(){
	freopen("energy.in","r",stdin);
	freopen("energy.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) ans[i][1]=1;
	for(int i=1;i<=n;i++){
		for(int j=2;j<=k;j++){
			if(i>=j) ans[i][j]=ans[i-1][j-1]+ans[i-j][j];//这个算1份的情况数+和这一个不算一份
			else ans[i][j]=ans[i-1][j-1];
			ans[i][j]%=MOD;
		}
	}
	cout<<ans[n][k];
	return 0;
}