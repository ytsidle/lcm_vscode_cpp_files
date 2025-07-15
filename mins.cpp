#include <bits/stdc++.h>
using namespace std;
const int MAX=1e9+7,fa=INT_MAX;
priority_queue <long long,vector<long long>,greater<long long> > q;
long long ans;
int main(){
	int n,k;
	long long t;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&t);
		q.push(t);
	}
	for(int i=1;i<=k;i++){
		t=q.top();
		q.pop();
		t*=2;
		q.push(t);
	}
	while(!q.empty()){
		ans+=q.top();
		q.pop();
		if(ans>=fa) ans%=MAX;
	}
	printf("%lld",ans);
	return 0;
}
