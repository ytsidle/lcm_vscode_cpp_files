#include <bits/stdc++.h>
long long n,a[100010],sum;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=((a[i]-a[i-1])<0)?0:(a[i]-a[i-1]);
	}printf("%d",sum);
	return 0;
}
