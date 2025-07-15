#include <bits/stdc++.h>
using namespace std;
long long n,ans;
int main(){
//	freopen("gcd.in","r",stdin);
//	freopen("gcd.out","w",stdout);
	cin>>n;
	for(long long c=2;c<=n;c++){
		int k=n/c;
		for(long long j=1;j<=k;j++){
			//a^b==c
			//a^b^a==b==c^a
			long long t=(j*c);//a
			long long b=(t^c);//b
			if((t^b)==t-b) ans++;
		}
	}
	cout<<ans;
	return 0;
}
