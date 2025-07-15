#include <bits/stdc++.h>
using namespace std;
bool is_prime(int n){
	if(n<2) return 0;
	if(n==2) return 1;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0) return 0;
	}return 1;
}
int main(){
	int n;
	cin>>n;
	for(int i=2;i<=n;i++){
//		cout<<i<<endl;
		int sum=0,num=i;
//		cout<<num<<endl;
		if(is_prime(i)){
			while(num){
				sum+=num%10;
				num/=10;
			}if(is_prime(sum)) cout<<i<<" ";
		}
	}
	return 0;
}
