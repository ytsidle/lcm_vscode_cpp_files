#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull n,ans,amax;
int main(){
	cin>>n;
	amax=(ull)log2(n);
//	cout<<amax;
	ull cnt=1;
	for(ull i=1;i<=amax;i++){
		cnt*=2;
		ull bmax=sqrt((ull)n/cnt);
		ans+=(ull)ceil(bmax/2.0);
//		cout<<cnt<<" "<<ceil(bmax/2.0)<<endl;
	}
	cout<<ans;
	return 0;
}
