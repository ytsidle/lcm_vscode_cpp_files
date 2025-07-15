#include <bits/stdc++.h>
using namespace std;
long long n,a[6000],b[6000],k,ans;
struct Data{
	long long x,y;
}d[6000];
bool cmp(Data a,Data b){
	if(a.x!=b.x) return a.x<b.x;
	else{
		return a.y<b.y;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]){
			if(a[i]>b[i]) swap(a[i],b[i]);
			d[++k]={a[i],b[i]};
		}
	}
	sort(d+1,d+1+k,cmp);
	for(int i=1;i<=k;i++){
		if(d[i-1].x!=d[i].x||d[i-1].y!=d[i].y)ans++;
	}cout<<ans;
	return 0;
}
