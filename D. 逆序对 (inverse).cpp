#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAX=1e9+7;
int n,m,a[1010],s[1010][3],b[1010];
long long ans=0;
inline void merge_sort(int l,int r){
	if(l==r) return;
	int mid=(l+r)>>1;
	merge_sort(l,mid);
	merge_sort(mid+1,r);
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r){
		if(a[i]<=a[j]){
			b[k++]=a[i++];
		}else{
			b[k++]=a[j++];
			ans+=mid-i+1;
			ans%=MAX;
		}
	}
}
void solve(){
	merge_sort(1,n);
}
void dfs(int num){
	if(num==m+1){
		solve();
		return;
	}
	dfs(num+1);
	swap(a[s[num][1]],a[s[num][2]]);
	dfs(num+1);
	swap(a[s[num][1]],a[s[num][2]]);
}
int main(){
	freopen("inverse.in","r",stdin);
	freopen("inverse.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&s[i][1],&s[i][2]);
	}
	dfs(1);
	printf("%lld",ans%MAX);
	return 0;
}
