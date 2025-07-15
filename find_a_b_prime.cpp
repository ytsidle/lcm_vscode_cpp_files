#include <bits/stdc++.h>
using namespace std;
bool is_p(int n){
	if(n==2) return 1;
	if(n<2) return 0;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0) return 0;
	}return 1;
}
int main(){
	int a,b,cnt=0;
	cin>>a>>b;
	for(int i=a;i<=b;i++){
		if(is_p(i)) cnt++;
	}cout<<cnt;
	return 0;
}
