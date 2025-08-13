#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
struct Node{
	ld x,y;
}d[200];
ll n,k,f[200],vis[200]; 
ld man(ll i,ll j){
	return (abs(d[i].x-d[j].x)+abs(d[i].y-d[j].y));
}
int main(){
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>d[i].x>>d[i].y;
	}
	for(int i=2;i<=k;i++){
		f[i]=LONG_LONG_MAX;
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		ld sux=d[i].x,suy=d[i].y;
		ll nu=1;
		vis[i]=1;
		for(int j=2;j<=k;j++){
			d[0]={sux/nu,suy/nu};
			ll mi=(-1);
			// ld mia=LDBL_MAX;
			ld mia=LDBL_MAX;
			for(int p=1;p<=n;p++){
				if(vis[p]) continue;
				if(mi==-1||mia>man(0,p)){
					mia=man(0,p);
					mi=p;
				}
			}
			sux+=d[mi].x,suy+=d[mi].y;
			nu++;
			vis[mi]=1;
			ld averx=1.0*sux/nu,avery=1.0*suy/nu,an=0;
//			cout<<averx<<" "<<avery<<"\n";
			d[0]={averx,avery};
			for(int p=1;p<=n;p++){
				if(!vis[p]) continue;
				an+=man(0,p);
			}
			f[j]=min(f[j],(ll)ceil(an));
//			cout<<i<<" "<<j<<" "<<mi<<" "<<an<<"\n";
		}
	}
	for(int i=1;i<=k;i++){
		cout<<f[i]<<"\n";
	}
	return 0;
}