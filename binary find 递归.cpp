#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+10;
int n,a[MAX],x;
int bin(int l,int r){
	int mid=(l+r)/2;
	if(l>r) return -1;
	if(a[mid]<x){
		return bin(mid+1,r);
	}else if(a[mid]>x){
		 return bin(l,mid-1);
	}else {
		return mid;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}cin>>x;
	cout<<bin(1,n);
	return 0;
}
