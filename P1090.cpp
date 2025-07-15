#include <bits/stdc++.h>
using namespace std;
int n;
long long f[10010];
bool cmp(long long a,long long b){
	return a<b;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&f[i]);
	}
	sort(f+1,f+n,cmp);
	for(int i=3;i<=n;i++){
		f[i]+=(f[i-1]+f[i-2])*2;
//		sort(f+1,f+n,cmp);
	}
	printf("%lld",f[n]);
	return 0;
}
