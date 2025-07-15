#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
long long n,a[MAX],ans=INT_MIN;
inline __gcd(int a,int b){
	while(1){
		if(a==0) return b;
		if(b==0) return a;
		a=a%b;
		swap(a,b);
	}
}
int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i]=a[i-1]+a[i];
	}
	for(int i=1;i<n;i++){
		ans=max(ans,__gcd(a[i],a[n]-a[i]));
	}
	printf("%lld",ans);
	return 0;
}
