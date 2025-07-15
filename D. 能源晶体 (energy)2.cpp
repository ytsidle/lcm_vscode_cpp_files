#include <bits/stdc++.h>
using namespace std;
const int p=998244353;
int n,k,a[5050];
long long ans=0;
inline void dfs(int num,int use){
	if(n-use<a[num-1]){
		return;
	}
	if(num==k){
		a[num]=n-use;
//		for(int i=1;i<=num;i++){
//			cout<<a[i]<<" ";
//		}
//		cout<<endl;
		ans+=1;
		ans%=p;
		return;
	}
	for(int i=a[num-1];i<=n-use-(k-num)*i;i++){
//		cout<<num<<" "<<i<<endl;
		a[num]=i;
		dfs(num+1,use+i);
	}
}
int main(){
	freopen("energy.in","r",stdin);
	freopen("energy.out","w",stdout);
	scanf("%d%d",&n,&k);
	a[0]=1;
	dfs(1,0);
	printf("%lld",ans%p);
	return 0;
}
