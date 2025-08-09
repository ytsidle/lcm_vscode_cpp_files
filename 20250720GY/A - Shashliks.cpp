#include <bits/stdc++.h>
#define int long long
using namespace std;
int k,a,b,x,y,T;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--) {
		cin>>k>>a>>b>>x>>y;
		int ans=0,ans2=0,ans3=0,tmp=0,rk=k;
		k=rk;
		if(k>=b) {
			//选B花的少
			tmp=(k-b)/y+1;
			ans+=tmp;
			k-=tmp*y;
			//无法在烤制b了,
			if(k>=a) {
				tmp=(k-a)/x+1;
				ans+=tmp;
				k-=tmp*x;
			}
		} k=rk;
		if(x==y) {
			int mi=min(a,b);
			if(k>=mi) ans2=(k-mi)/x+1;
		}k=rk;
		if(k>=a) {
			tmp=(k-a)/x+1;
			ans3+=tmp;
			k-=tmp*x;
			if(k>=b) {
				tmp=(k-b)/y+1;
				ans3+=tmp;
				k-=tmp*y;
			}
		}
		cout<<max(ans,max(ans2,ans3))<<"\n";
	}
	return 0;
}
