#include <bits/stdc++.h>
using namespace std;
long long a[4];
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%lld%lld%lld",&a[1],&a[2],&a[3]);
	sort(a+1,a+4);
	if(a[2]==a[3]){
		printf("YES\n%lld %lld %lld",1,a[1],a[3]);
	}else printf("NO");
	return 0;
}
