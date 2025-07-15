#include <bits/stdc++.h>
using namespace std;
const int MAX=5e4+10;
int st=1,n,a[MAX][2],q,c,cnt;
int bfind(int num){
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(num>=a[mid][0]) l=mid+1;
		else r=mid-1;
		
	}
	return l;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&c);
		a[i][0]=st;
		st+=c;
		a[i][1]=i;
//		printf("%d %d\n",a[i][0],a[i][1]);
	}
	for(int i=1;i<=q;i++){
		scanf("%d",&c);
		int p=bfind(c+1);
//		cout<<"p:"<<p<<endl;
		printf("%d\n",a[p-1][1]);
	}
	return 0;
}
