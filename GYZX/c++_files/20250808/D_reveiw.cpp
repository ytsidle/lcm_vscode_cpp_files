#include <bits/stdc++.h>
#define int long long
#define  INF 1e17
using namespace std;
int n,k,p,dp[6][6][6][6][6],cl[105],a[105][6],l[6];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k>>p;
//	memset(dp,0x3f,sizeof(dp));
	for(int as=0;as<=5;as++){
		for(int b=0;b<=5;b++){
			for(int c=0;c<=5;c++){
				for(int d=0;d<=5;d++){
					for(int e=0;e<=5;e++){
						dp[as][b][c][d][e]=INF;
					}
				}
			}
		}
	}
	for(int i=1;i<=k;i++) l[i]=p;
	dp[0][0][0][0][0]=0;
	for(int i=1;i<=n;i++){
		cin>>cl[i];
		for(int j=1;j<=k;j++){
			cin>>a[i][j];
		}
		int a1=a[i][1],a2=a[i][2],a3=a[i][3],a4=a[i][4],a5=a[i][5];
		for(int b=5;b>=0;b--){
			if(b>l[1]) continue;
			for(int c=5;c>=0;c--){
				if(c>l[2]) continue;
				for(int d=5;d>=0;d--){
					if(d>l[3]) continue;
					for(int e=5;e>=0;e--){
						if(e>l[4]) continue;
						for(int f=5;f>=0;f--){
							if(f>l[5]) continue;
//							if(dp[b][c][d][e][f]==INF) continue;
							int x1=min(p,b+a1),x2=min(c+a2,p),x3=min(p,d+a3),x4=min(p,e+a4),x5=min(p,f+a5);
							dp[x1][x2][x3][x4][x5]=min(dp[x1][x2][x3][x4][x5],dp[b][c][d][e][f]+cl[i]);
							//dp[i][x1][x2][x3][x4][x5]=min(dp[i-1][x1][x2][x3][x4][x5],dp[i-1][b][c][d][e][f]+cl[i]);
//							if(dp[x1][x2][x3][x4][x5]!=INF) cout<<" f sfd \n";
						}
					}
				}
			}
		}
	}
	if(dp[l[1]][l[2]][l[3]][l[4]][l[5]]==INF) cout<<-1;
	else cout<<dp[l[1]][l[2]][l[3]][l[4]][l[5]];
	return 0;
}