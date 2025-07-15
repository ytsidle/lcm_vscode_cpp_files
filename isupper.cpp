#include <bits/stdc++.h>
using namespace std;
char chars;
int isuppers(char a){
	return int(a);
}
int main(){
	cin >> chars;
	if(isuppers(chars)>=65&&isuppers('Z')>=isuppers(chars)){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
//	cout<<isuppers(chars);
	cout<<isuppers('1');
	return 0;
}
