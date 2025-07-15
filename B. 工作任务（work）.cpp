#include <bits/stdc++.h>
using namespace std;
const int M=2e5+10;
long long n,m,k,suma[M],sumb[M],ans=LONG_LONG_MAX;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("work.in","r",stdin);
	freopen("work.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>suma[i];
		suma[i]+=suma[i-1];
	}
	for(int i=1;i<=m;i++){
		cin>>sumb[i];
		sumb[i]+=sumb[i-1];
	}
	for(int  i=0;i<=n&&suma[i]<=k;i++){
		long long p=upper_bound(sumb+1,sumb+1+m,k-suma[i])-sumb-1;
		if(p!=-1){
			ans=min(i+p,ans);
		}
	}
	cout<<ans;
	return 0;
}
