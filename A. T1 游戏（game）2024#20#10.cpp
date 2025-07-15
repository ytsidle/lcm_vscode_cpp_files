#include <bits/stdc++.h>
using namespace std;
/*
	要使得分最高
	相当于求一个数的质因数分解,求最多有几个质数相乘
	要使l-r区间内的数产生的得分最高:
	满足log_2(num)=l<=2^x<=r
	若存在,保证x为最优解
	if 条件为log_2(r)-log_2(l)>=1|| log2(r)==int(log_2(r):
		cout<<log_2(r)
	if  log2(l)==int(log_2(l)):
		cout<<log_2(l);
	2 2 2 2 2
	大了
	
		
*/
int l,r;
int main(){
	
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&l,&r);
	double lol=log2(l),lor=log2(r);
	int iol=lol,ior=lor;
	if(ior-iol>=1||lor==(double)ior){
		printf("%d",ior+1);	
	}
	
	else{
		printf("%d",iol+1);
	}
	return 0;
}
