// Problem: E. Multitest Generator
// Contest: Codeforces - Codeforces Round 860 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1798/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define int long long
const int inf=1e18;
const int N=6e5+10;
using namespace std;
int t,a[N],ans[N],g[N],f[N],cf[N],ok[N],n;

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
		
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i],f[i]=0;
		f[n+1]=g[n+1]=0;
		cf[n+1]=0;
		fill(ok,ok+2+n,1);
		// if(a[n]==0)f[n]=1;
		// else f[n]=0;
		// ok[n]=1,g[n]=1;
		for(int i=n;i;i--){
			if(f[i+1]==a[i]){
				ans[i]=0;
			}
			else if(g[i+1]>=a[i]||ok[i+1]){
				ans[i]=1;
			}else ans[i]=2;
			if(i+a[i]+1<=n+1){
				f[i]=f[i+a[i]+1]+1;
				ok[i]&=ok[i+a[i]+1];
			}else ok[i]=0,f[i]=0;
			cf[i]=max(cf[i+1],f[i]);
			if(ok[i])g[i]=max(g[i+a[i]+1]+1,cf[i+1]+1);
			else g[i]=cf[i+1]+1;
		}
		for(int i=1;i<n;i++) cout<<ans[i]<<" ";
		cout<<"\n";
	}
	
	return 0;
}