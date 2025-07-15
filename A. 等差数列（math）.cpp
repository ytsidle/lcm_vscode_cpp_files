#include <bits/stdc++.h>
using namespace std;
int a,b;
int main(){
	cin>>a>>b;
	if(b>a) swap(a,b);
	if(a==b)cout<<1;
	else if((a-b)%2==0) cout<<3;
	else cout<<2;
	return 0;
}
