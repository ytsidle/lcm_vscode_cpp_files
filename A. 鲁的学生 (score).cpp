#include <bits/stdc++.h>
using namespace std;
const int INF=1e9+7,N=1e7+10;
long long n,x,ans;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&x);ans+=(x*1ll*i)%INF*(n-i+1);ans%=INF;
	}
	printf("%lld",ans);
	return 0;
}