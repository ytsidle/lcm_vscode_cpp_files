#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const ll M=105;
ll ans[M],x[M],y[M],d[M],n,ks;
int main(){
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%lld%lld",&n,&ks);
//	for(int i=1;i<=ks;i++) ans[i]=LLONG_MAX;
	memset(ans,0x3f,sizeof(ans));
	for(int i=1;i<=n;i++) scanf("%lld%lld",&x[i],&y[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
//			memset(d,0,sizeof(0));
			for(int k=1;k<=n;k++) {
				d[k]=abs(x[i]-x[k])+abs(y[j]-y[k]);
			}
			sort(d+1,d+1+n);
			for(int k=1;k<=ks;k++) {
				d[k]+=d[k-1];
				ans[k]=min(ans[k],d[k]);
			}
		}
	}
	printf("0\n");
	for(int i=2;i<=ks;i++){
		printf("%lld\n",ans[i]);
	}
	return 0;
}