#include <bits/stdc++.h>
using namespace std;
int an,bn,cn,dn,ra,rb,rc,rd,n;
string s;
int main(){
	cin>>n>>an>>bn>>cn>>dn;
	cin>>s;
	for(int i=0;i<s.size();i++){
		switch(s[i]){
			case 'A':
				ra++;
				break;
			case 'B':
				rb++;
				break;
			case 'C':
				rc++;
				break;
			case 'D':
				rd++;
				break;
		}
	}
	cout<<(min(ra,an)+min(rb,bn)+min(rc,cn)+min(rd,dn));
	return 0;
}
