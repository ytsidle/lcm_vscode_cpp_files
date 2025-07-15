#include <bits/stdc++.h>
using namespace std;
int n,a[1005],k;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j!=i){
				if(a[i]+a[j]==k){
					cout<<"yes";
					return 0;
				}
			}
		}
	}cout<<"no";
	return 0;
}
