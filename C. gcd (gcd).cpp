#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
int main(){
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(__gcd(i,j)==(i^j)&&i!=j){
//				cout<<i<<' '<<j<<" "<<(i^j)<<endl;
				ans++;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
