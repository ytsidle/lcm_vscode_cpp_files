#include <bits/stdc++.h>
using namespace std;
int k;
unsigned long long n,e,d,p,q,ans1,ans2;
//bool is_ok(unsigned long long n1,unsigned long long n2,unsigned long long s,unsigned long long e1,unsigned long long d1){
//	return (n1*n2==s)&&((d1*e1)==((n2 - 1)*(n1 - 1)+1));
//}
int main(){
	cin>>k;
	for(int i=1;i<=k;i++){
		scanf("%llu%%ll%ll",&n,&d,&e);
		p=n-(e*d);
		q=n/p;
		if(n%p==0) cout<<min(q,p)<<" "<<max(q,p)<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
