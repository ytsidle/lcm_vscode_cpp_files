#include <bits/stdc++.h>
using namespace std;
int t,l,r,ans;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&l,&r);
		ans=l;
		for(int i=l+1;i<=r;i++){
			ans=ans|i;
		}
		printf("%d\n",ans);
	}
	return 0;
}
