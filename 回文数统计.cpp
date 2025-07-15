#include <bits/stdc++.h>
using namespace std;
int n,cnt;
bool is(int n){
	int cn=n,m=0;
	while(n){
		m=m*10+n%10;
		n/=10;
		
	}if(cn==m){
		return 1;
	}return 0;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		if(is(i)){
			cnt++;
		}
	}cout<<cnt;
	return 0;
}
