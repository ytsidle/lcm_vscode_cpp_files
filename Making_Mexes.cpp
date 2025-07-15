#include <bits/stdc++.h>
using namespace std;
int n,a[200010],cnt[200010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	int zeronum=0;
	for(int i=0;i<=n;i++){
		cout<<zeronum+cnt[i]-(zeronum<=cnt[i]?zeronum:cnt[i])<<endl;
		if(cnt[i]==0) zeronum++;
	}
	return 0;
}
