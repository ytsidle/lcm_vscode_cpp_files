#include <bits/stdc++.h>
using namespace std;
const int M=2e5+10;
//警察集玩多了后遗症
int f[M],cnt[M],edges[M],n,m,a[M][2],ans;
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		f[fy]=fx;
		cnt[fx]+=cnt[fy];
		cnt[fy]=0;
		edges[fx]+=edges[fy];
		edges[fy]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) f[i]=i,cnt[i]=1;
	for(int i=1;i<=m;i++){
		cin>>a[i][0]>>a[i][1];
		edges[a[i][0]]++;
		edges[a[i][1]]++;
	}
	for(int i=1;i<=m;i++){
		merge(a[i][0],a[i][1]);
	}
	for(int i=1;i<=n;i++){
		if(cnt[i]==(edges[i]/2)+1) ans++;

	}cout<<ans;
	return 0;
}
