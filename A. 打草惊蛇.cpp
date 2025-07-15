#include <bits/stdc++.h>
using namespace std;
long long n,m,a[30],ans=0,cnt=0;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	//枚举
	for(long long db=1;db<=m;db++){
		cnt=0;
		for(int i=1;i<=n;i++){
			if(db%a[i]==0) cnt++;
		}ans=max(ans,cnt);
	}cout<<ans;
	return 0;
}
