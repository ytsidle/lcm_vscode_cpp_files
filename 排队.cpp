#include <bits/stdc++.h>
using namespace std;
int n,l=1,r;
inline int len(int a,int b){
	return abs(a-b);
}
struct Data{
	int no,act;
}d[6000],answer[6000];
bool cmp(Data a,Data b){
	return a.act>b.act;
}
long long dp[3000][3000],ans=0;
int main(){
    freopen("queue.in","r",stdin);
    freopen("queue.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i].act);
		d[i].no=i;
	}
	sort(d+1,d+1+n,cmp);
	for(int i=0;i<=n-1;i++){
		for(int j=0;j<=n-1;j++){
			int k=i+j+1;
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]+1ll*d[k].act*len(d[k].no,(i+1)));
			dp[i][j+1]=max(dp[i][j+1],dp[i][j]+1ll*d[k].act*len(d[k].no,(n-j)));
		}

	}
	for(int i=0;i<=n;i++){
		ans=max(ans,dp[i][n-i]);
	}
	cout<<ans;
	return 0;
}