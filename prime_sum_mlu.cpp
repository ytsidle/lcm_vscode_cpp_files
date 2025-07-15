#include <bits/stdc++.h>
using namespace std;
int n,cnt,a[10000],k=1,ma;
bool is_prime(int a){
	if(a==2) return true;
	if(a<2) return false; 
	for(int i=2;i<=sqrt(a);i++){
		if(a%i==0) return false;
	}return true;
}
int main(){
	cin>>n;
	for(int k=2;k<=n;k++){
		
		if(is_prime(k)&&is_prime(n-k)){
			ma=max(k*(n-k),ma);
			
			
		}
	}
		
	cout<<ma;
	return 0;
}
