#include <bits/stdc++.h>
using namespace std;
int n,k,x[220],y[220];
long long ans[220],f[220];
void cal(int A,int B){
	for(int i=1;i<=n;i++){
		f[i]=abs(A-x[i])+abs(B-y[i]);
	}
	sort(f+1,f+1+n);
	long long t=0;
	for(int i=1;i<=k;i++){
		t+=f[i];
		ans[i]=min(ans[i],t);
	}
}
int main(){
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	memset(ans,0x3f,sizeof(ans));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cal(x[i],y[j]);
		}
	}
	for(int i=1;i<=k;i++) printf("%lld\n",ans[i]);
	return 0;
}
