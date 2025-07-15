#include <bits/stdc++.h>
using namespace std;
int n;
void f(int num){
	if(num==1) cout<<1<<" ";
	else{
		
		f(floor(num*1.0/2));
		cout<<num<<" ";
		f(num-floor(num*1.0/2));
	}
}
int main(){
	cin>>n;
	f(n);
	return 0;
}
