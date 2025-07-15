#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
struct data{
	long long x,t;
}d[MAX];
long long n,m,sum,lp,ans;
priority_queue<long long> q;
int main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&d[i].x,&d[i].t);
	}
	for(int i=1;i<n;i++){
		ans+=d[i].x-lp;
		q.push(d[i].t);
		sum+=d[i].t;
		while(sum>m&&!(q.empty())){
			long long tp=q.top();
			
			q.pop();
			sum-=tp;
		}
		lp=d[i].x;
	}
	ans+=d[n].x-lp;
	q.push(d[n].t);
	sum+=d[n].t;
	bool flag=0;
	while(sum+ans>m&&!(q.empty())){
		long long tp=q.top();
		if(tp==d[n].t)flag=1;	
		q.pop();
		sum-=tp;
	}if(flag) ans-=d[n].x-lp;
	
	cout<<q.size();
	return 0;
}