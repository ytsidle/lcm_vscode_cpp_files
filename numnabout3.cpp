#include <bits/stdc++.h>
using namespace std;
int n;
void fun(int num){
	if(num%10%3==0){
		cout<<num<<" ";
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		fun(i);
	}
	return 0;
}
