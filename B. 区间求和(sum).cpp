#include <bits/stdc++.h>
using namespace std;
#define LL long long
//Hash+前缀和
const int M=1e7+10,p=1e7+2,N=1e5+10;
LL a[N],b[N],n,m,ans;
vector<LL> h[M];
inline bool find(LL x){
	int pos=x%p;
	for(int i=0;i<h[pos].size();i++){
		if(h[pos][i]==x) return 1;
	}
	return 0;
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(LL i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i]=b[i-1]+a[i];
		h[b[i]%p].push_back(b[i]);
	}
	for(LL i=0;i<=n;i++){
		if(find(b[i]+m)){
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
