#include <bits/stdc++.h>
using namespace std;
//打表
long long MAXN=1e18+10,b[1000100],cnt,n;
int a[100],i;
inline long long qpow(int i){
	return 1ll*i*i*i;
}
inline bool is(long long num){
	int k=0;
	while(num){
		a[++k]=num%10;
		num/=10;
	}
	for(int i=1;i<=ceil(k/2.0);i++){
		if(a[i]!=a[k-i+1]) return 0;
	}return 1;
}
int main(){
//	cout<<(qpow(1000000)==MAXN);
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout);
	for(int i=1;i<=1000001;i++){
		if(qpow(i)<=MAXN){
			if(is(qpow(i))){
				b[++cnt]=qpow(i);
			}
		}
	}
	scanf("%lld",&n);
	for(i=1;i<=cnt;i++){
		if(b[i]>n) break;
	}
	printf("%lld",b[i-1]);
	return 0;
}
