#include <bits/stdc++.h>
#define int long long 
const int MOD=998244353;
using namespace std;
const int M=2e5+10;
int n,k,m[M],num[M],mul,dp[5000][5000];
set<int> s;
void dfs(int c,int cnt){
	if(c>n){
		if(cnt==k){
			int t=1;
			int ans=0;
			for(int i=1;i<=n;i++){
				int mi=INT_MAX;
				for(int j=i-1;j>=1;j--){
					if(num[i]!=num[j]){
						mi=min(i-j,mi);
						break;
					}
				}
				for(int j=i+1;j<=n;j++){
					if(num[i]!=num[j]){
						mi=min(j-i,mi);
						break;
					}
				}
				ans+=mi*t;
				t*=mul;
			}
			s.insert(ans);
		}return;
	}
	for(int i=1;i<=k;i++){
		num[c]=i;
		if(m[i]==0){
			m[i]++;
			dfs(c+1,cnt+1);
			m[i]--;
		}
		else{
			dfs(c+1,cnt);
		}
	}
	
}
signed main(){
	freopen("difference.in","r",stdin);
	freopen("difference.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	mul=20;
	if(n==k){
		cout<<1;
		return 0;
	}
	dfs(1,0);
	cout<<s.size();
	return 0;
}