#include <bits/stdc++.h>
using namespace std;
int n,l,r;
int main(){
	cin>>n>>l>>r;
	int c=l/n*n;
	if(c+n-1<=r){
		cout<<n-1;
	}else{
		cout<<r-c;
	}
	return 0;
}
