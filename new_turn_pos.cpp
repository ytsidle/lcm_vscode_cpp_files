#include <bits/stdc++.h>
using namespace std;
int n,a[25],t1,t2,t3,t4;
int main(){
	cin>>n;

	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>t1>>t2;
	cin>>t3>>t4;
	for(int i=t1,j=t3;i<=t2;i++,j++){
		swap(a[i],a[j]);
		
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
