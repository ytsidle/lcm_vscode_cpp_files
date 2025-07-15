#include <bits/stdc++.h>
using namespace std;
const int MAX=5e4+10;
int len,n,m,a[MAX],l,r,mid;
int che(int num){
	int ans=0,f=0;
	for(int i=1;i<=n+1;i++){
		if(a[i]-f<num){
			ans++;
		}else f=a[i];
	}return ans;
}
int main(){
	cin>>len>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	a[n+1]=len;
	int l=0,r=len;
	while(l<=r){
		mid=(l+r)>>1;
		if(che(mid)<=m){
			l=mid+1;
		}else r=mid-1;
	}cout<<r;
	return 0;
}
