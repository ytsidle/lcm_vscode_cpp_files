#include <bits/stdc++.h>
using namespace std;
int n,a[52014];
int main(){
	cin>>n;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2){
			if(a[i]<=a[i-1]) flag=0;
		}
	}
	if(flag) cout<<"Yes";
	else cout<<"No";
	return 0;
}
