#include <bits/stdc++.h>
using namespace std;
int n,a[110],ans;
bool check(int pos){
	int goal=a[pos];
	for(int i=1;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			
			if(a[i]+a[j]==goal){
//				cout<<a[i]<<" "<<a[j]<<endl;
				return 1;
			}
		}
	}return 0;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(check(i)){
			ans++;
		}
	}cout<<ans;
	return 0;
}
