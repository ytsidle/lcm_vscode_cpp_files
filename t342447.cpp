#include <bits/stdc++.h>
using namespace std;
const int MAX=2e5+10;
int a[MAX],q,t,k,n,l,r,mid;
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,1+a+n);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&t,&k);
		if(t==1){
			l=1,r=n;
			//左边界
			while(l<=r){
				mid=(l+r)>>1;
				if(k<a[mid]) r=mid-1;
				else l=mid+1;
			}
			if(a[l]!=0) printf("%d\n",a[l]);
			else printf("-1\n");
		}else{
			l=1,r=n;
			//右边界
			while(l<=r){
				mid=(l+r)>>1;
				if(a[mid]>=k) r=mid-1;
				else l=mid+1;
			}
			if(r!=0 && r!=n+1) printf("%d\n",a[r]);
			else printf("-1\n");
		}
	}
	return 0;
}
