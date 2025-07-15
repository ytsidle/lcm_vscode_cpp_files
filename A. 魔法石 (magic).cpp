#include <bits/stdc++.h>
using namespace std;
#define LL long long 
LL x,y,z;
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%lld%lld%lld",&x,&y,&z);
	if(x==y&&y==z){
		printf("YES\n%d %d %d",x,x,x);
		exit(0);
	}
	if(x==z&&x!=y&&y<=z){
		LL a=x,b=y,c=1;
		printf("YES\n%d %d %d",a,b,c);
		exit(0);
		
	}
	if(x==y&&x!=z&&z<=x){
		LL b=x,a=1,c=z;
		printf("YES\n%d %d %d",a,b,c);
		exit(0);
	}
	if(y==z&&x!=y&&x<=z){
		LL a=1,b=x,c=z;
		printf("YES\n%d %d %d",a,b,c);
		exit(0);		
	}
	//全部不相等
	/*
		max(a,b)!=max(b,c)!=max(a,c)
		因为max(a,b)!=max(b,c)
		所以可以有a,b  a,c b,c三种
		因为max(b,c)!=max(a,c)
		所以有 b,a  b,c   c,a
		max(a,b)!=max(a,c)
		a,c b,a b,c
	*/
	printf("NO");
	return 0;
}
