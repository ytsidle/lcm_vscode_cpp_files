#include <bits/stdc++.h>
using namespace std;
void fourleves(long long num){
	long long sum=0,dnum=num;
	int nums=0,len=0;
	while(dnum){
		nums=(dnum%10);
		sum+=pow(nums,4);
		dnum/=10;
		len++;
	}if(sum==num&&len==4){
		
		printf("%lld ",num);
	}
}
int main(){
	long long n,m;
	scanf("%lld%lld",&n,&m);
	for(long long i=n;i<=m;i++){
		fourleves(i);
	}
	return 0;
}
