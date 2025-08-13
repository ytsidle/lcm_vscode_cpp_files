#include <bits/stdc++.h>
#define int long long 
using namespace std;

signed main(){
	int n;
	int a[19];
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		if(i%2==1)  ans+=-a[i]*(n-i+1)*(n-i+1);
		else ans+=a[i]*(n-i+1)*(n-i+1);
	}cout<<ans;
	return 0;
}