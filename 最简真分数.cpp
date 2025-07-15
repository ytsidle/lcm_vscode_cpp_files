#include <bits/stdc++.h>
using namespace std;
int a[650],n,ans;
int gcd(int a,int b){
	while(a!=0 && b!=0){
		a=a%b;
		swap(a,b);
	}

	if(a==0) return b;
	else if(b==0) return a;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(gcd(a[i],a[j])==1 && a[i]!=a[j]){
				ans++;
			}
		}
	}cout<<ans;
	return 0;
}
