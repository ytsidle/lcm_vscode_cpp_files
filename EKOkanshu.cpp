#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6+100;
long long a[MAX],n,m,ma;
long long can(long long h){
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]>h){
			sum+=a[i]-h;
		}
	}return sum;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]>ma) ma=a[i];
	}
	long long l=0,r=ma,mid=(l+r)/2,num;
	while(l<=r){
		mid=(l+r)/2;
//		cout<<ma<<" "<<l<<" "<<r<<" "<<mid<<endl;
		num=can(mid);
//		cout<<num<<endl;
		if(num<m) r=mid-1;
		else l=mid+1;
		
	}cout<<r;
	return 0;
}
