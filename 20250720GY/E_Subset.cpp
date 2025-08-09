#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M=6e5+10;
int a[M],n,T;
int lcm(int x,int y){
	return x*y/__gcd(x,y);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		int ans=1;
		for(int i=n;i>1;i--){
			if(a[i]%a[i-1]!=0||1){
				int gg=__gcd(a[i],a[i-1]);
				ans=lcm(ans,a[i-1]/gg);
				a[i-1]=gg;
			}
		}cout<<ans<<"\n";
	}
	return 0;
}
