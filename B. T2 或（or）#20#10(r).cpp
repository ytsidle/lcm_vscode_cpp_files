#include <bits/stdc++.h>
using namespace std;

long long l,r,t,ans,k,an;

int main(){
	freopen("or.in","r",stdin);
	freopen("or.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld",&l,&r);
		an=0;
		for(int i=0;i<=30;i++){
			long long y;
			if(l&(1ll<<i)) y=l;
			else{
				y=(l|1ll<<i);
				for(int j=0;j<i;j++){
					if(y&(1ll<<j)) y^=(1ll<<j);
				}
			}
			if(y<=r){
				an|=(1ll<<i);
			}
		}
		printf("%lld\n",an);
	}
	
	
	return 0;
}
