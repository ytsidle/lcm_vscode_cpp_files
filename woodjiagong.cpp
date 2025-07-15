#include <bits/stdc++.h>
using namespace std;
const int MAX=1e8+10;
int n,k,a[MAX],l,r,mid,ma;
int ge(int he){
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i]/he;
	}return ans;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>ma) ma=a[i];
	}
	int l=0,r=ma;
	while(l<=r){
		mid=(l+r)/2;
		if(mid==0){
			break;
			r=0;
		}
		if(ge(mid)>=k) l=mid+1;
		
		else r=mid-1;
//		if(r==l && r==0) break;
	}cout<<r;
	return 0;
}
