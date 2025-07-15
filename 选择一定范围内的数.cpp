#include <bits/stdc++.h>
using namespace std;
int a[10010],n,l,r,sum;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}scanf("%d%d",&l,&r);
	for(int i=1;i<=n;i++){
		if(a[i]<=r&&a[i]>=l){
			sum++;
		}
	}printf("%d",sum);
	return 0;
}
