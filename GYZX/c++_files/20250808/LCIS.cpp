#include <bits/stdc++.h>
using namespace std;
int dp[505][505],n,m,a[505],b[505],k,l[505],lp[505][2],pos[505][505][2],ans[1000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}cin>>m;
	for(int i=1; i<=m; i++) {
		cin>>b[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(a[i]==b[j]) {
				//找最近继承
				if(a[i]>l[k]){
					l[++k]=a[i];
					dp[i][j]=k;
					lp[k][0]=i,lp[k][1]=j;
					pos[i][j][0]=lp[k-1][0],pos[i][j][1]=lp[k-1][1];
				}else{
					int p=lower_bound(l+1,l+k+1,a[i])-l-1;
					dp[i][j]=p+1;
					l[p+1]=min(a[i],l[p+1]);
					lp[p+1][0]=i,lp[p+1][1]=j;
					pos[i][j][0]=lp[p][0],pos[i][j][1]=lp[p][1];
				}
			}else{
//				dp[i][j]=max({dp[i-1][j],dp[i][j-1]});
				if(dp[i-1][j]>dp[i][j-1]){
					pos[i][j][0]=i-1,pos[i][j][1]=j;
				}else{
					pos[i][j][0]=i,pos[i][j][1]=j-1;
				}
			}
//			cout<<dp[i][j]<<" ";
		}
//		cout<<"\n";
	}cout<<dp[n][m]<<"\n";
	int cnt=0,i=n,j=m;
	while(i&&j){
		if(a[i]==b[j]){
			ans[++cnt]=a[i];
		}
		int ti=pos[i][j][0],tj=pos[i][j][1];
		i=ti,j=tj;
	}
	for(int tt=cnt;tt;tt--) cout<<ans[tt]<<" ";
	return 0;
}