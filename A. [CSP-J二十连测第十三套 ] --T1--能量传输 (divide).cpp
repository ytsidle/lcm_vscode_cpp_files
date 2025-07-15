#include <bits/stdc++.h>
#define int long long
#define INT int
using namespace std;
const int N = 1e7 + 5;

int n, a[N], b[N],sum;
int ans=LLONG_MAX;
void solve(int k){
//	memcpy(b,a,sizeof(a));
	int cnt=0,s=0,res=0,mid=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			
			cnt++;
			if(cnt==k+1) cnt=1;
			if(cnt<ceil(k/2.0)) {
				s+=i;
			}
			else if(cnt==ceil(k/2.0)){
				res+=(cnt-1)*i-s;
				mid=i;
			} 
			else res+=i-mid;
		}
	}

	ans=min(ans,res);
}
signed main(){
	freopen("divide.in","r",stdin);
	freopen("divide.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n==1){
		printf("0");
		exit(0);
	}
	int sum = std::accumulate(a + 1, a + 1 + n, 0LL);
	for(int k=2;k*k<=sum;k++){
		if(sum%k==0){
			solve(k);
			while(sum%k==0) sum/=k;
			
		}
	}
	if(sum!=1) solve(sum);
	printf("%lld",ans==LLONG_MAX?-1:ans);
	return 0;
}
