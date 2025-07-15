#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	cin>>s;
	for(int  i=0;i<s.size();i++){
		if(s[i]=='N') cout<<'S';
		if(s[i]=='S') cout<<'N';
		if(s[i]=='E') cout<<'W';
		if(s[i]=='W') cout<<'E';
	}
	return 0;
}
