#include <bits/stdc++.h>
using namespace std;
const int MAX=900000000;
long long f[MAX];
long  long n,m,t,ans,s;
bool flag;
int main(){
//	scanf("%ld%ld",&m,&n);
	m=1,n=9999999;
	f[++t]=2;
//			ans++;
	if(m<=2) ans++;
	
	for(long long i=3;i<=n;i+=2){
		s=1;
		flag=true;
		while(f[s]<=sqrt(i)){
//			cout<<n<<" "<<s<<endl;
			if(i%f[s]==0){
				flag=false;
				break;
			}
			s++;
		}if(flag&&i>=m){
			ans++;
			
		}f[++t]=i;	
	
	}
	cout<<ans;
	return 0;
}
