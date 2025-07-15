#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll M=1e6+10;
ll n,s[M],p[M],a[M],t[M];
vector<pair<ll,ll> > v;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(i==1){
			t[1]=s[i]+p[i]+a[i];
			continue;
		}
		//如果上一个没有挡道
		if(t[i-1]<s[i]+p[i-1]||p[i]<p[i-1]){//入座时间少于我到达那里的时间
			t[i]=s[i]+p[i]+a[i];
		}
		else{
//			cout<<i<<"dd\n";
			//会挡住
			//求出挡住多久
			ll ans=0,adt=0,lp=0;
//			v.clear();
//			for(int j=i-1;j>=1;j--){
//				if(p[j]<p[i]){
//					v.push_back({p[j],j});
//				}
//			}
//			sort(v.begin(),v.end());
//			for(pair<ll,ll> tmp:v){
//				cout<<tmp.first<<"dd"<<tmp.second<<"\n";
//				ll id=tmp.second;
//				if(t[id]>=s[i]+p[id]+adt){
//					adt+=t[id]-(s[i]+p[id]+adt);
//					ans=t[id]+p[i]-p[id];
//				}
//			}
//			t[i]=ans;
			for(int j=i-1;j>=1;j--){
				if(p[j]<p[i]){
					if(t[j]>=s[i]+p[j]+adt){
//						lp=max(lp,p[j]);
						adt+=t[j]-(s[i]+p[j]+adt);
						ans=max(ans,t[j]+p[i]-p[j]);
						
					}
				}
			}
			t[i]=ans;
		}
	}
	for(int i=1;i<=n;i++) cout<<t[i]<<"\n";
	return 0;
}
