#include <bits/stdc++.h>
using namespace std;
long long n,ans=1;
int main(){
	cin>>n;
	if(n%2==0) ans=max(ans,max(2*1ll,n/2));
	for(long long i=3;i<=sqrt(n);i+=2){
		if(n%i==0) ans=max(ans,max(i,n/i));
	}
	cout<<ans;
	return 0;
}
