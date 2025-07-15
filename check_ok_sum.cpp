#include <bits/stdc++.h>
using namespace std;
int n,k,t;
long long ans;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		if(t%10==k){
			ans+=t;
		}
	}
	printf("%lld",ans);
	return 0;
}
