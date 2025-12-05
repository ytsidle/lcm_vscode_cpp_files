#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define ll long long
const int N=1e5+5;
const int M=(1<<21)+14;
int n,m,pos[22][N],a[N],cnt[22],sum[M],dp[M];
inline int P(int S,int b){
	int l=sum[S]+1,r=sum[S]+cnt[b];
	int lp=lower_bound(pos[b]+1,pos[b]+1+pos[b][0],l)-pos[b];
	int rp=upper_bound(pos[b]+1,pos[b]+1+pos[b][0],r)-pos[b]-1;
	return cnt[b]-(rp-lp+1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]--;
		cnt[a[i]]++;
		pos[a[i]][++pos[a[i]][0]]=i;
	}
	for(int i=1;i<=(1<<m)-1;i++){
		for(int j=0;j<=__lg(i);j++){
			if(i&(1<<j)){
				sum[i]+=cnt[j];
			}
		}
	}
	memset(dp,0x3f,sizeof(dp));
	int mi=dp[0];
	int lim=(1<<m)-1;
	dp[0]=0;
	for(int i=1;i<=m;i++){
		for(int s=lim;s>=1;s--){
			if(__builtin_popcount(s)!=i) continue;
			for(int k=0;k<=__lg(s);k++){
				if(s&(1<<k)){
					int s2=s^(1<<k);
					if(dp[s2]!=mi){
						dp[s]=min(dp[s],dp[s2]+P(s2,k));
					}
				}
			}
		}
	}
	cout<<dp[lim];
	return 0;
}