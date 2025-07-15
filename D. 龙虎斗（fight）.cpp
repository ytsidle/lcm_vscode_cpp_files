#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
long long n,a[MAX],m,p,sa,sb;
long long as,bs;
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%lld%lld%lld%lld",&m,&p,&sa,&sb);
	a[p]+=sa;
	for(int i=1;i<m;i++){ 
		as+=1ll*a[i]*(m-i);
	}
	for(int i=m+1;i<=n;i++) bs+=1ll*a[i]*(i-m);
//	cout<<as<<" "<<bs<<endl;
//	if(bs==as){
//		printf("%lld",m);
//		return 0;
//	}
	if(as<bs){
		int cha=bs-as,chap=m;
		for(int i=1;i<m;i++){
			int t=abs((as+(m-i)*sb)-bs);
			if(t<cha||(t<=cha&&i<chap)){
				chap=i;
				cha=t;
			}
		}
		printf("%d",chap);
	}else{
		int cha=as-bs,chap=m;
		for(int i=m+1;i<=n;i++){
			int t=abs(bs-(as+(i-m)*sb));
			if(t<cha||(t<=cha&&i<chap)){
				chap=i;
				cha=t;
			}
		}
		printf("%lld",chap);
	}
	return 0;
}
