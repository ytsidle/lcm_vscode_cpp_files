#include <bits/stdc++.h>
using namespace std;
string a;
bool ourisdigit(string a){
	for(int i=0;i<a.length();i++){
		if(!(a[i]>='0'&&a[i]<='9')){
			return false;
		}
	}return true;
}
int main(){
	cin >> a;
//	cout<<ourisdigit(a)?"yes":"no";
	if(ourisdigit(a)){
		cout<<"yes";
	}else{
		cout<<"no";
	}
	return 0;
}
