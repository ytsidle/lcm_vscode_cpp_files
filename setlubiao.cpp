#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int len,n,k,a[MAX],l,r,mid;
int che(int num){
	int f=0,ans=0;
	for(int i=2;i<=n;i++){
		if(a[i]-f>num){
			ans++;
			f=f+num;
			i--;
		}else{
			f=a[i];
		}
	}return ans;
}
int che1(int num){
	int ans=0,t=0;
	for(int i=2;i<=n;i++){
		t=ceil((a[i]-a[i-1])*1.0/num)-1;
//		cout<<"t:"<<t<<endl;
		ans+=t;
	}return ans;
}
int main(){
	scanf("%d%d%d",&len,&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}l=1,r=len;
//	cout<<che1(50)<<endl;
	while(l<=r){
		mid=(l+r)/2;
		if(che(mid)<=k) r=mid-1;
		else l=mid+1;
	}cout<<l;
	return 0;
}
