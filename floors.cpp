#include <bits/stdc++.h>
using namespace std;
int n;
int a=1,b=2,c=a+b;
int main(){
	while(cin>>n){
		a=1,b=2,c=a+b;
		for(int i=1;i<=n-2;i++){
			c=a+b;
			a=b;
			b=c;
		}
		cout<<c<<endl;
	}
	return 0;
}
