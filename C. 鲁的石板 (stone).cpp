#include <bits/stdc++.h>
using namespace std;
const unsigned long long M=1e9+7;
int T,n,m;
unsigned long long qkpow(long long a,long long b){
	unsigned long long sum=1;
	while(b){
		if(b&1)//与运算，可判断奇偶，详细见注释
		sum=sum*a%M;//取模运算
		a=a*a%M;
		b>>=1;//位运算，右移，相当于除以2
	}
	return sum;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		if(n==1) printf("%d\n",m);
		else if(n==2) printf("%d\n",m*(m-1));
		else{
			unsigned long long ans=m*qkpow(m-1,n-2)*(m-2);
			ans%=M;//求出了只算a[1]!=a[n-1]
			//求出a[1]==a[n-1]
			/*
			n=3
			1 0
			n=4
			1 0 1
			n=5
			1 0 0,1 1,0 0,1
			5 4 3 1  
			5*4*4*3*1
			*/
			if(n>=4)ans+=m*qkpow(m-1,n-4)*(m-2)*1;
			ans%=M;
			printf("%llu\n",ans);
		}
	}
	return 0;
}
