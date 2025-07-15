#include <bits/stdc++.h>
using namespace std;
const int MAX=100000+100;
int n,m,a[MAX],x,f[MAX];
int bin(int num){
	int l=1,r=n,mid=(l+r)/2;
	while(l<=r){
		mid=(l+r)/2;
		if(num<=a[mid]) r=mid-1;
		else  l=mid+1;
//		cout<<"bin">>a[mid]>>" ">>l>>" ">>r<<endl;
	}if(l<1||l>n||a[l]!=num) return -1;
	return l;
}int bin1(int num){
	int l=1,r=n,mid=(l+r)/2;
	while(l<=r){
		mid=(l+r)/2;
		if(num<a[mid]) r=mid-1;
		else l=mid+1;
//		cout<<"bin">>a[mid]>>" ">>l>>" ">>r<<endl;
	}if(a[l-1]!=num) return -1;
	return l-1;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		
	}for(int i=1;i<=m;i++){
		scanf("%d",&f[i]);

	}
	for(int i=1;i<=m;i++){
		int left=bin(f[i]);
		int right=bin1(f[i]);
		printf("%d %d\n",left,right);
	}
	return 0;
}
