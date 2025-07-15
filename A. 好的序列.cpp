#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int ma,n,ans,x;
int main(){
	freopen("increase.in","r",stdin);
	freopen("increase.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(x==ans+1) ans++;
		else ans=0;
		ma=max(ma,ans);
	}
	printf("%d",ma);
	return 0;
}
