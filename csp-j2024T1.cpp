#include <bits/stdc++.h>
using namespace std;
set<string> s;
string str;
int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>str;
		s.insert(str);
	}
	cout<<52-s.size();
	return 0;
}
