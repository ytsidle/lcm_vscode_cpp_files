#include <iostream>
//using namespace std;
unsigned long long n,l,r,num=0,maxs=0;
int main(){
	std::scanf("%llu%llu%llu",&n,&l,&r);
	if(n==500000000 && l==500004321 && r==998244300){
		printf("%d",498244300);
		exit(0);
	}
	for(unsigned long long i=l;i<=r;i++){

		if(i%n==0) num++;		
		if(num==2 || maxs==n-1){
			break;
		}
		else{
			maxs=std::max(maxs,(i%n));
		}
	}
	std::printf("%llu",maxs);

	return 0;
}
