#include <bits/stdc++.h>
using namespace std;
unsigned long long a,b,c;
unsigned long long al,bo;
int main(){
	cin>>a>>b>>c;
	
	al=a*a;
	bo=b*c;
	if(al>bo) cout<<"Alice";
	else cout<<"Bob";
	return 0;
}
