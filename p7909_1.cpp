#include <iostream>
//using namespace std;
unsigned long long n,l,r,num=1;
int main(){
	std::scanf("%llu%llu%llu",&n,&l,&r);
	while(!(l<num*n-1) && num*n-1<=r){
		num++;
	}if(!(num*n-1<=r)) num--;
	std::printf("%llu",((num*n)-1)%n);
	return 0;
}
