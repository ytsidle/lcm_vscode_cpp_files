#include <bits/stdc++.h>
using namespace std;
int n,t=2,a[10000],k;
int main(){
	cin>>n;
	if(n%2==1){
		cout<<-1;
		return 0;
	}
	while(n){
		a[++k]=n%2;
		n/=2;
	}
	for(int i=k;i>=2;i--){
		if(a[i]==1){
			cout<<pow(2,i-1)<<" ";
		}
	}
	return 0;
}
