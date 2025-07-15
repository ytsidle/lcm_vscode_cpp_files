#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int n,m,l,r,mid,a[MAX];
int check(int num){
	int ans=0,ls=0;
	for(int i=1;i<=n;i++){
		if(ls+a[i]>num){
			ans++;
			ls=a[i];
		}else{
			ls+=a[i];
		}
	}return ans;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		l=max(l,a[i]);
		r+=a[i];
	}while(l<=r){
		mid=(l+r)/2;
		if(check(mid)>=m) l=mid+1;
		else r=mid-1;
	}cout<<l;
	return 0;
}
