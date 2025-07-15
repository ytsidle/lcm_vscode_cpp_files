#include <bits/stdc++.h>
using namespace std;
int T,n,k,a[105];
string as="";
bool check(int starts,int length,int times){
	int p=starts;
	for(int i=2;i<=times;i++){
		if(as.substr(p,length)!=as.substr(p+length,length)) return 0;
	}return 1;
}
int solve(int l,int r){
	if(l==r) return 1;
	for(int i=l;i<=r-2;i++){
		for(int len=1;i+len-1<=r;len++){
			for(int k=1;l-1+k*len<=r;k--){
				if(len%k==0){
					if(check(i,len,k)){
						
					}
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>k;
		as="";
		for(int i=1;i<=n;i++){
			cin>>a[i];
			as+=a[i];
		}
		if(n==1){
			cout<<"YES\n";
			continue;
		}
		solve(1,n);
	}
	return 0;
}
