#include <bits/stdc++.h>
using namespace std;
string inp;
bool is_ok(string in){
	string l,r,lp,rp;
	l=in.substr(0,in.find('='));
	r=in.substr(in.find('=')+1);
//	cout<<l<<endl;
	lp=l.substr(0,l.find('+'));
	rp=l.substr(l.find('+')+1);
	int a=atoi(lp.c_str()),b=atoi(rp.c_str());
	l=to_string(a+b);
	return l==r;
}
int main(){
//	cout<<is_ok("11+11=22");
	getline(cin,inp);
	for(int i=1;i<inp.find('=');i++){
		inp.insert(i,"+");
		if(is_ok(inp)){
			printf("%s",inp.c_str());
			exit(0);
		}inp.erase(i,1);
	}
	printf("Impossible!");
	return 0;
}
