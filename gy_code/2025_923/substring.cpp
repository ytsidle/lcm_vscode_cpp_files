#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=3e5+10;
ll n,q,cnt[N];
pair<ll,ll> a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		cnt[i]=cnt[i-1]+n-a[i].second+1;
	}
	while(q--){
		ll k;
		cin>>k;
		int p=lower_bound(cnt+1,cnt+1+n,k)-cnt;
		int s=k-cnt[p-1];
		int st=a[p].second;
		cout<<st<<" "<<st+s-1<<"\n";
	}
	return 0;
}
