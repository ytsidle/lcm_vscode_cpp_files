#include <bits/stdc++.h>
using namespace std;
int n,x,a[110],cnt;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>x;
	for(int i=1;i<=n;i++){
		if(a[i]<=x){
			x-=a[i];
			cnt++;
		}
	}cout<<cnt;
	return 0;
}
