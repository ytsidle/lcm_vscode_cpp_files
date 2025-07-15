#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int cnt[3400],n,a[MAX],zero=1700,ma=INT_MIN,mi=INT_MAX,t;
long long ans;
int main(){
//	freopen("assess.in","r",stdin);
//	freopen("assess.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		t=zero+a[i];
		ma=max(ma,t);
		mi=min(mi,t);
		cnt[t]++;
	}
	for(int i=mi;i<=ma;i++){
		if(cnt[i]>0){
			for(int j=i+1;j<=ma;j++){
				if(cnt[j]>0){
					t=abs((i-zero)-(j-zero));
					t=t*t;
					ans+=cnt[i]*cnt[j]*t;
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
