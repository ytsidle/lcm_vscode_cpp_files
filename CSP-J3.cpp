#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=2e6+10;
int t[M],a[N],s[N],n,k,dp[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=2e6+5;i++) t[i]=-1;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			dp[i]=dp[i-1]+1;
			t[s[i]]=i;
			continue;
		}
		int l=t[(s[i]^k)];
		if(l!=-1){
			dp[i]=dp[l]+1;
		}
		t[s[i]]=i;
		dp[i]=max(dp[i],dp[i-1]);
	}cout<<dp[n];
	return 0;
}
