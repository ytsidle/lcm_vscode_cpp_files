#include <bits/stdc++.h>
using namespace std;
string a=" abcdefghijklmnopqrstuvwxyz";
string in;
int main(){
	getline(cin,in);
	for(int i=1;i<=in.size();i++){
		if(in[i-1]!='!')
		cout<<a.find(in[i-1])<<" ";
		else cout<<endl;
	}
	return 0;
}
