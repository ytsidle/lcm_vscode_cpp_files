#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
bool huiwen(int n){
	int a=n,b=0;
	while(a){
		b=b*10+a%10;
		a/=10;
	}if(n==b){
		return true;
	}return false;
}
bool has_seven(int n){
	while(n>0){
		if(n%10==7){
			return true;
		}
		n/=10;
	}return false;
}
int main(){
	cin>>n>>m;
	for(int i=n;i<=m;i++){
		if(has_seven(i)&&huiwen(i)){
			ans++;
		}
	}cout<<ans;
	return 0;
}
