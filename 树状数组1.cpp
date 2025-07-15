#include <bits/stdc++.h>
using namespace std;
const int MAX=5e5+10;
long long a[MAX],tr[MAX],n,m;
int lowbit(int x){
	return x & -x;
}
long long query(int x){
	long long ans=0;
	for(int i=x;i;i-=lowbit(i)){
		ans+=tr[i];
	}
	return ans;
}
void update(int x,long long k){
	for(int i=x;i<=n;i+=lowbit(i)) tr[i]+=k;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		update(i,a[i]);
	}
	for(int i=1;i<=m;i++){
		int op,fir,sec;
		scanf("%d%d%d",&op,&fir,&sec);
		if(op==1){
			update(fir,sec);
		}else{
			printf("%lld\n",query(sec)-query(fir-1));
		}
	}
	return 0;
}
