#include <bits/stdc++.h>
using namespace std;
int n,a[200];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		if(a[i-2]==a[i-1]&&a[i-1]==a[i]){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
	return 0;
}
