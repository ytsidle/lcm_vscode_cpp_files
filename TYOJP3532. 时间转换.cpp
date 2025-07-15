#include <bits/stdc++.h>
using namespace std;
int s,m,h;
int main(){
	cin>>s;
	m=s/60;
	s%=60;
	h=m/60;
	m%=60;
	cout<<h<<":"<<m<<":"<<s;
	return 0;
}
