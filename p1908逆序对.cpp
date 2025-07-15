#include <bits/stdc++.h>
using namespace std;
//离散化
const int MAX=5e5+10;
#define int long long
int n,a[MAX],b[MAX],tree[MAX],ans;
int lowbit(int x){
	return -x&x;
}
int query(int num){
	int sum=0;
	for(int i=num;i;i-=lowbit(i)){
		sum+=tree[i];
	}
	return sum;
}
void update(int x){
	for(int i=x;i<=n;i+=lowbit(i)){
		tree[i]++;
	}
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i]=a[i];
	}
	//离散化
	sort(b+1,b+1+n);
	int e=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+1+e,a[i])-b;
	
	for(int i=1;i<=n;i++){
		ans+=query(n)-query(a[i]);
		update(a[i]);
	}
	printf("%lld",ans);
	return 0;
}
