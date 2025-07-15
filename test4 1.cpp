#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[40];
int main(){
	//input
	cin>>n>>m;
	cin>>k;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	//if can,don't
	
	/*
		if can't{
		on left ok stop
		on right ok stop	
	*/
	int l=1,r=m,ans=0;
	for(int i=1;i<=k;i++){//i apple is loss
		if(a[i]>=l && a[i]<=r) ans+=0;
		else{
			if(a[i]<l){
				ans+=l-a[i];
				l=a[i];
				r=l+m-1;
			}else if(a[i]>r){
				ans+=a[i]-r;
				r=a[i];
				l=r-m+1;
			}
		}
	}
	cout<<ans;
				
}
