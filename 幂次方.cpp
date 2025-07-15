#include <bits/stdc++.h>
using namespace std;
long long n;
const long long M = 1e10+2;
bitset<M> isPower;
int main(){
//    freopen("pow.in","r",stdin);
//    freopen("pow.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	long long a=sqrt(n),dele=0;
	for(int i=2;i<=a;i++){
		long long t=i*i;
		while(t<=n){
			if(isPower[t]==0){
				dele++;
				isPower[t]=1;
			}
			t*=i;
		}
	}
	cout<<(n-dele);
	return 0;
}
