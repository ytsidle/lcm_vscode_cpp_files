#include <bits/stdc++.h>
using namespace std;
//1.判断n,m是否是奇数,
//确定奇数范围,以:(s+e)*((e-s))/2;
int main(){
	int n,m,num=0;
	scanf("%d%d",&m,&n);
	if(m%2==0){
		m++;
	}if(n%2==0){
		n--;
	}
	for(int i=m;i<=n;i+=2){
		num+=i;
	}
	printf("%d",num);
//	printf("%d",((n+m)*((n-m)/2))/2);
	return 0;
}
