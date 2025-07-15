#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long dp[2*N][3],cnt[2*N][3],p[N*2][3][3],n,m,k,a[N],b[N],ans=0;
int main(){
//	freopen("work.in","r",stdin);
//	freopen("work.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n+m;i++){	
		//处理第一个
		//链接第一个
		long long cntf=LONG_LONG_MAX,cnts=LONG_LONG_MAX-1;
		if(cnt[i-1][1]<=k){
			cntf=cnt[i-1][1]+a[(p[i-1][1][1]+1)];
		}if(cnt[i-1][2]<=k){
			cnts=cnt[i-1][2]+a[(p[i-1][2][1]+1)];
		}
		if(a[(p[i-1][1][1]+1)]==0) cntf=LONG_LONG_MAX;
		if(a[(p[i-1][2][1]+1)]==0) cnts=LONG_LONG_MAX-1;
		if(cntf<cnts&&cntf<=k){
			//从dp[i-1][1]转移
			cnt[i][1]=cntf;
			p[i][1][1]=p[i-1][1][1]+1;
			p[i][1][2]=p[i-1][1][2];
			dp[i][1]=dp[i-1][1]+1;
		}else if(cntf==cnts&&cntf<=k){
			//根据dp值进行分析
			if(dp[i-1][1]<=dp[i-1][2]){
				//dp[i-1][2]转移
				cnt[i][1]=cnts;
				p[i][1][1]=p[i-1][2][1]+1;
				p[i][1][2]=p[i-1][2][2];
				dp[i][1]=dp[i-1][2]+1;
			}else{
				//从dp[i-1][1]转移;
				cnt[i][1]=cntf;
				p[i][1][1]=p[i-1][1][1]+1;
				p[i][1][2]=p[i-1][1][2];
				dp[i][1]=dp[i-1][1]+1;
			}
		}
		else{
			//从dp[i-1][2]转移
			cnt[i][1]=cnts;
			p[i][1][1]=p[i-1][2][1]+1;
			p[i][1][2]=p[i-1][2][2];
			dp[i][1]=dp[i-1][2]+1;
		}
		//---------处理dp[i][2]-------------
		if(cnt[i-1][1]<=k){
			cntf=cnt[i-1][1]+b[(p[i-1][1][2]+1)];
		}if(cnt[i-1][2]<=k){
			cnts=cnt[i-1][2]+b[(p[i-1][2][2]+1)];
		}
		if(b[(p[i-1][1][2]+1)]==0) cntf=INT_MAX;
		if(b[(p[i-1][2][2]+1)]==0) cnts=INT_MAX-1;
		if(cntf<cnts&&cntf<=k){
			//从dp[i-1][1]转移
			cnt[i][2]=cntf;
			p[i][2][1]=p[i-1][1][1];
			p[i][2][2]=p[i-1][1][2]+1;
			dp[i][2]=dp[i-1][1]+1;
		}else if(cntf==cnts&&cntf<=k){
			//根据dp值进行分析
			if(dp[i-1][1]<=dp[i-1][2]){
				//dp[i-1][2]转移
				cnt[i][2]=cnts;
				p[i][2][1]=p[i-1][2][1];
				p[i][2][2]=p[i-1][2][2]+1;
				dp[i][2]=dp[i-1][2]+1;
			}else{
				//从dp[i-1][1]转移;
				cnt[i][2]=cntf;
				p[i][2][1]=p[i-1][1][1];
				p[i][2][2]=p[i-1][1][2]+1;
				dp[i][2]=dp[i-1][1]+1;
			}
		}
		else{
			//从dp[i-1][2]转移
			cnt[i][2]=cnts;
			p[i][2][1]=p[i-1][2][1];
			p[i][2][2]=p[i-1][2][2]+1;
			dp[i][2]=dp[i-1][2]+1;
		}
	}
	for(int i=1;i<=n+m;i++){
//		cout<<cnt[i][1]<<" "<<cnt[i][2]<<" dp "<<dp[i][1]<<" "<<dp[i][2]<<endl;
		if(cnt[i][1]<=k){
			ans=max(ans,dp[i][1]);
		}
		if(cnt[i][2]<=k){
			ans=max(ans,dp[i][2]);
		}
	}
	cout<<ans;
	return 0;
}
