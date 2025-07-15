#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+1000;
//采用二分,以a[i]为对象在b里找第一个小于等于a[i]的值,使差值最小,i从1到p
int p,an,bn,a[MAX],b[MAX];//an=a num  bn=b num(缩写)
int main(){
	cin>>p>>an>>bn;
	for(int i=1;i<=an;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=bn;i++){
		scanf("%d",&b[i]);
	}
	sort(a+1,a+1+an);
	sort(b+1,b+1+bn);
	int ans=0,l=1,r=bn,mid=(l+r)/2;
//	for(int i=1;i<=an;i++){
//		cout<<a[i]<<" ";
//	}cout<<endl;
//	for(int i=1;i<=bn;i++){
//		cout<<b[i]<<" ";
//	}cout<<endl;
	for(int i=1;i<=p;i++){
		l=1,r=bn,mid=(l+r)/2;
		while(l<r){
			if(b[mid]>=a[i]) r=mid-1;
			else l=mid+1;
			mid=(l+r)/2;
		}
//		cout<<l<<" "<<min(abs((a[i]-b[l])*2),abs((a[i]-b[l+1])*2))<<endl;
		ans +=min(abs((a[i]-b[l])*2),abs((a[i]-b[l+1])*2));
	}
	cout<<ans;
	return 0;
}
