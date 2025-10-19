#include<bits/stdc++.h>
using namespace std;

const int MOD=998244353;
int ans;
int n,k;
void dfs(int c,int sum,int mi){
	if(sum<mi) return;
	if(c==k){
		ans++;
		if(ans>MOD) ans=1;
		return ;
	}
	for(int i=mi;i<=sum-mi*(k-c);i++){
		dfs(c+1,sum-i,i);
	}
	
}
int main(){
//	freopen("energy.in","r",stdin);
//	freopen("energy.out","w",stdout);
	cin>>n>>k;
	ans=0;
	dfs(1,n,1);
	cout<<ans<<"\n";
		

	return 0;
}