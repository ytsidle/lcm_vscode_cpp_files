#include <bits/stdc++.h>
using namespace std;
string a;
int main(){
	getline(cin,a);
	cout<<a;
	for(int i=0;i<4;i++){
		a[i]=((a[i]-48)+5)%10+48;
	}
	for(int i=3;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
