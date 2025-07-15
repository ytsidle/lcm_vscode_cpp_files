#include <bits/stdc++.h>
using namespace std;
int n,m,f[6000],use[6000],ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int l,r;
		cin>>l>>r;
		for(int j=l;j<=r;j++){
			f[j]=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(f[i]!=0){
			ans+=(!use[f[i]]);
			use[f[i]]=1;
		}
	}cout<<ans;
	return 0;
}
