#include <bits/stdc++.h>
using namespace std;
int cnt[20],n,x,tw,th;
int main(){
	n=7;
	for(int i=1;i<=n;i++){
		cin>>x;
		cnt[x]++;
	}
	for(int i=1;i<=13;i++){
		if(cnt[i]==2) tw++;
		if(cnt[i]>=3) th++;
	}
	if(th>=2) cout<<"Yes";
	else if(th>=1&&tw>=1) cout<<"Yes";
	else cout<<"No";
	return 0;
}
