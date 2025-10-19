#include <bits/stdc++.h>
using namespace std;
//#define int long long
int T,l,r;
signed main(){
	freopen("OR.in","r",stdin);
	freopen("OR.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--){
		int l,r;
		cin>>l>>r;
		int ans=0;
		for(int i=0;i<=30;i++){
			if(l&(1<<i)){
				ans+=(1<<i);
			}else{
				int tmp=l;
				tmp>>=i;
				tmp|=1;
				tmp<<=i;
				if(tmp<=r)ans+=(1<<i);
			}
		}cout<<ans<<"\n";
	}
	return 0;
}