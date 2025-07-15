#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	cin>>n;
	for(int i=n/2+2;i>=1;i--){
		if(i<=n&&2*i<=n){
			cout<<i;
			return 0;
		}
	}
	return 0;
}
