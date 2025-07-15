#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],b[N],n,m,k,ha=1,hb=1,ans,sum;
int main(){
	freopen("work.in","r",stdin);
	freopen("work.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	while(1){
		if((a[ha]<b[hb]&&ha<=n)||hb==m+1){
			if(sum+a[ha]<=k&&ha<=n){
				sum+=a[ha];
				ans++;
				ha++;
			}
			else break;
		}else if((b[hb]<a[ha]&&hb<=m)||ha==n+1){
			if(sum+b[hb]<=k&&hb<=m){
				sum+=b[hb];
				ans++;
				hb++;
			}
			else{
				break;
			}
		}else break;
	}
	cout<<ans;
	return 0;
}
