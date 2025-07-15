#include <bits/stdc++.h>
using namespace std;
int a[1000005],n,key;
int half(int key){
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]<key){
			l=mid+1;
		}else if(a[mid]>key){
			r=mid-1;
		}else{
			return mid;
		}
	}
	return -1;
	
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>key;
	if(key<a[1]||key>a[n]){
		cout<<-1;
		return 0;
	}
	cout<<half(key);
	return 0;
}
