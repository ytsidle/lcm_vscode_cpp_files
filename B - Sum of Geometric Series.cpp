#include <bits/stdc++.h>
using namespace std;
const unsigned long long MAX=1e9;
unsigned long long n,t,cnt;
int m;
int main(){
	cin>>n>>m;
	t=0,cnt=1;
	for(int i=1;i<=m+1&&t<=MAX;i++){
		t+=cnt;
		cnt*=n;
		if(t>MAX){
			cout<<"inf";
			exit(0);
		} 
	}
	cout<<t;
	return 0;
}
