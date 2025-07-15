#include <bits/stdc++.h>
using namespace std;
int n;
long long mi=LONG_LONG_MAX;
long long mins(long long a,long long b){
	if(a<b) return a;
	else return b;
}
int main(){
	cin>>n;
	for(int i=1;i<=3;i++){
		int x,y;
		cin>>x>>y;
		mi=mins(mi,1ll*ceil(n*1.0/x)*y);
	}
	cout<<mi;
	return 0;
}
