#include <bits/stdc++.h>
using namespace std;
const unsigned int MAX=2e9+10;
bitset<MAX> b;
long long n,ans=1,t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=2;i<=sqrt(n);i++){
		t=i*i;
		while(t<=n){
			if(b[t]==0){
				ans++;
//				cout<<t<<endl;
				b[t]=1;
			}
			t*=i;
		}
	}
	printf("%lld",ans);
	return 0;
}
