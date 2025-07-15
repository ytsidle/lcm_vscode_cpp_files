#include <bits/stdc++.h>
using namespace std;
char in[60];
string a;
int main(){
	getline(cin,a);
	for(int i=0;i<a.length();i++){
//		if(isupper(in[i])) in[i]=in[i]+32;
//		if(in[i]=='_') in[i]='-';
		in[i+1]=a[i];
	}
	for(int i=1;i<=a.length();i++){
		if(isupper(in[i])) in[i]=in[i]+32;
		if(in[i]=='_') in[i]='-';
	}
	for(int i=0;i<a.length();i++){
//		if(isupper(in[i])) in[i]=in[i]+32;
//		if(in[i]=='_') in[i]='-';
		a[i]=in[i+1];
	}
	cout<<"solution-"<<a;
	return 0;
}
