#include <bits/stdc++.h>
using namespace std;
long long n;
long long sum(long long num){
	long long re=0;
	while(num!=0){
		re+=num%10;
		num/=10;
	}return re;
}
int main(){
	cin>>n;
	for(long long i=1;i<=n;i++){
		if(sum(i)%2==0){
			cout<<i<<" ";
		}
	}
	return 0;
}
