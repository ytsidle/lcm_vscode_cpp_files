#include <bits/stdc++.h>
using namespace std;
int n,maxs,t,a[20];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxs){
			maxs=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==maxs){
			cout<<i<<endl;
		}
	}
	return 0;
}
