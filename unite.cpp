#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int n,a[MAX],ans=INT_MAX;
void dfs(int num,int gnu,int sum){
	if(num==n+1){
		if(gnu==1){
			ans=min(ans,sum);
		}
		return;
	}
	dfs(num+1,__gcd(gnu,a[num]),sum);
	dfs(num+1,__gcd(gnu,__gcd(num,a[num])),sum+n-num+1);
}
int main(){
	freopen("unite.in","r",stdin);
	freopen("unite.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(1,a[1],0);
	printf("%d",ans);
	return 0;
}
