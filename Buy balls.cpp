#include <bits/stdc++.h>
using namespace std;
int n,m,b[200010],w[200010],sumb[200010],sumw[200010],msumw[200010];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	sort(b+1,b+1+n,greater<int>());
	sort(w+1,w+1+n,greater<int>());
	
	int ans=0;
	for(int i=1;i<=n;i++){
		sumb[i]=sumb[i-1]+b[i];
	}
	for(int i=1;i<=m;i++){
		sumw[i]=sumw[i-1]+w[i];
		msumw[i]=max(msumw[i-1],sumw[i]);
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,sumb[i]+msumw[min(i,m)]);
	}
	cout<<ans;
	return 0;
}
