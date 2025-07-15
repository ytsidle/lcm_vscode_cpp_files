#include <bits/stdc++.h>
using namespace std;
const int M=1e6+10;
int fa[M],cnt[M],n,q,ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		fa[i]=i;
		cnt[i]=1;
	} 
	ans=0;
	for(int i=1;i<=q;i++){
		int typ,p,h;
		cin>>typ;
		if(typ==1){
			cin>>p>>h;
			int fp=fa[p];
			if(cnt[fp]==2) ans--;
			cnt[fp]--;
			if(cnt[h]==1) ans++;
			cnt[h]++;
			fa[p]=h;
		}
		else{
			cout<<ans<<endl;
		}
	}
	return 0;
}
