#include <bits/stdc++.h>
using namespace std;
const unsigned long long MAX=1e6;
unsigned long long ans=1;
int n,a;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		ans*=a;
		if(ans>MAX){
			ans/=a;
			cout<<">1000000";
			return 0;
		}
	}cout<<ans;
	return 0;
}
