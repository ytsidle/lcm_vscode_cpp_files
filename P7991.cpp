#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int T,n,m,f[N],an,bn;
vector<int> g[N];
int find(int x) {
	return f[x]==x?x:f[x]=find(f[x]);
}
int get(int i,int j) {
	vector<int> a=g[i],b=g[j];
	an=a.size()-1,bn=b.size()-1;
//	cout<<i<<" : ";
//	for(auto ttt:a) cout<<ttt<<" ";cout<<endl;
	int mi=n-1;
	for(int i=1; i<=an; i++) {
		int p=lower_bound(b.begin(),b.end(),a[i])-b.begin();
		if(p==bn+1) {
			mi=min(mi,abs(a[i]-b[bn]));
		} else if(p==1) mi=min(mi,abs(a[i]-b[1]));
		else mi=min({mi,abs(a[i]-b[p-1]),abs(a[i]-b[p])});
	}
	return mi;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--) {
		cin>>n>>m;
		for(int i=1; i<=n; i++) {
			f[i]=i;
		}
		//接下来，把一下的点合成一坨坨大的~~(shit)~~
		for(int i=1; i<=m; i++) {
			int u,v;
			cin>>u>>v;
			int fx=find(u),fy=find(v);
			if(fx!=fy) f[fx]=fy;
		}
		if(n==1) {
			cout<<"0\n";
			continue;
		}
		int fo=find(1),fn=find(n);
		if(fo==fn) {
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			g[i].clear();
			g[i].push_back(0);
		}
		for(int i=1;i<=n;i++){
			g[find(i)].push_back(i);
		}
		for(int i=1;i<=n;i++)sort(g[i].begin(),g[i].end());
		int re=get(fo,fn);;
//		cout<<get()<<" -- "<<T+1<<"\n" ;
		int ans=re*re;
		int tmp=re/2;
		int ans2=(n-1)*(n-1);
		int ans3=(n-1)*(n-1);
		for(int i=1; i<=n; i++) {
			if(find(i)!=fo&&find(i)!=fn&&find(i)==i) {
				//计算
				ans3=min(ans3,get(i,fo)+get(i,fn)) ;
			}
		}
		cout<<min({ans,ans2,ans3})<<"\n";
	}
	return 0;
}