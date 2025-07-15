#include <bits/stdc++.h>
using namespace std;
string a,b,to;
int main(){
	to="rioi";
	cin>>a>>b;
	string ta=a,tb=b;
	for(int i=0;i<ta.size();i++){
		ta[i]=tolower(ta[i]);
	}
	for(int i=0;i<tb.size();i++){
		tb[i]=tolower(tb[i]);
	}
//	cout<<ta<<" "<<tb;
	int tya=ta.find(to),tyb=tb.find(to);
	if(tya!=-1&&tyb!=-1){
		cout<<"Either is ok!";
	}else if(tya!=-1&&tyb==-1){
		cout<<a<<" for sure!";
	}else if(tyb!=-1&&tya==-1){
		cout<<b<<" for sure!";
	}
	else cout<<"Try again!";
	return 0;
}
