#include <bits/stdc++.h>
using namespace std;
/*
先考虑k<=n/2的情况:
那么设d[i](i:1~n/2)=max(a[i],a[i+n/2])
排序,取前k个和;
-----------------
那么考虑一下k>n/2怎么办
我们考虑到(b[i]<=a[i)所以单个取肯定更优
思考:
首先按原来思路,a[i]中的佼佼者已经抓完了,
所以还要抓k-n/2个同伙,这时考虑找到前k-n/2大的组合
用struct(i,j)表示,用b[i]+b[j]-d[i]拍序接着ans


*/
bool cmp(int a,int b){
	return a>b;
}
int n,k,a[6000],b[6000],half,d[6000],g[6000];
long long ans=0;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	half=n/2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=half;i++){
		d[i]=max(a[i],a[i+half]);
	}
	if(k<=n/2){
		sort(d+1,d+1+half,cmp);
		for(int i=1;i<=k;i++) ans+=d[i];
	}else{
		for(int i=1;i<=half;i++) ans+=d[i];
		int need=k-half;
		for(int i=1;i<=half;i++){
			g[i]=b[i]+b[i+half]-d[i];
		}
		sort(g+1,g+1+half,cmp);
		for(int i=1;i<=need;i++) ans+=g[i];
	}
	cout<<ans;
	return 0;
}
