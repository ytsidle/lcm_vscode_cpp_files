#include <bits/stdc++.h>
using namespace std;
int n,m,cnt,dp[10050],l[10050];//l是差分，dp是dp
inline void push_down(){
	dp[0]+=l[0];
	for(int i=1;i<=m;i++){
		l[i]+=l[i-1];
		dp[i]+=l[i];
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int round=1;round<=n;round++){
		int x;
		cin>>x;
		if(x==0){
			++cnt;
			push_down();
			for(int i=m;i>=1;i--){
//				cout<<dp[i]<<" ";
				dp[i]=max(dp[i],dp[i-1]);
			}
			memset(l,0,sizeof(l));
//			cout<<"\n";
			continue;
		}if(x>0){
			l[x]++;
			l[cnt+1]--;
		}else{
			l[0]++;
			l[max(0,cnt+x+1)]--;
		}
	}
	push_down();
	int ans=0;
	for(int i=0;i<=m;i++) ans=max(dp[i],ans);
	cout<<ans;
	return 0;
}