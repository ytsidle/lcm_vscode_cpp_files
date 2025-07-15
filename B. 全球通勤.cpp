#include <bits/stdc++.h>
using namespace std;
const int MAX=5e6+10;
int cf[MAX],n,m,a[MAX],b[MAX],c[MAX];
long long ans;
int main(){
	freopen("global.in","r",stdin);
	freopen("global.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	}
	int x,y;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		cf[x]++;
		cf[y]--;
	}
	for(int i=1;i<n;i++){
		cf[i]=cf[i]+cf[i-1];
		ans+=min(1ll*cf[i]*a[i],(1ll*cf[i]*c[i]+b[i]));
	}
	printf("%lld",ans);
	return 0;
}
