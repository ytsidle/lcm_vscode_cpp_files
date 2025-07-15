#include <bits/stdc++.h>
using namespace std;
string a;
int gets_num(char in){
	int re=0;
	for(int i=0;i<a.length();i++){
		if(a[i]==in){
			re++;
		}
	}return re;
}
int main(){
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(gets_num(a[i])==1){
			cout<<a[i];
			return 0;
		}
	}cout<<"no";
	return 0;
}
