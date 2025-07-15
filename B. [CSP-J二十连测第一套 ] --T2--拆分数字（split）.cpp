#include <bits/stdc++.h>
using namespace std;
long long a[30],T,n,k;
inline bool countnum(long long num){
	if(num==k)return 1;
	long long ans=0,kn=0;
	while(num){
		int t=num%3;
		a[++kn]=t;
		num/=3;
		if(t) ans+=t;
	}
	if(ans==k) return 1;
	
	return 0;
}
int main(){
	scanf("%lld",&T);
	
	while(T--){
		
		scanf("%lld%lld",&n,&k);
		if(countnum(n)){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}
