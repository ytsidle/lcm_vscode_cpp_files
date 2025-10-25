#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int T,n,m,f[N],a[N],b[N],an,bn;
int find(int x) {
	return f[x]==x?x:f[x]=find(f[x]);
}
int get() {
	int mi=n-1;
	for(int i=1; i<=an; i++) {
		int p=lower_bound(b+1,b+1+bn,a[i])-b;
		if(p==bn+1) {
			mi=min(mi,abs(a[i]-b[bn]));
		} else if(p==1) mi=min(mi,abs(a[i]-b[1]));
		else mi=min({mi,abs(a[i]-b[p-1]),abs(a[i]-b[p])});
	}
	return mi;
}
int ge(int num) {
	int ans=0,mi=n-1;
	int p=lower_bound(b+1,b+1+bn,num)-b;
	if(p==bn+1) {
		mi=min(mi,abs(num-b[bn]));
	} else if(p==1) mi=min(mi,abs(num-b[1]));
	else mi=min({mi,abs(num-b[p-1]),abs(num-b[p])});
	ans+=mi;
	mi=n-1;
	p=lower_bound(a+1,a+1+an,num)-a;
	if(p==an+1) {
		mi=min(mi,abs(num-a[an]));
	} else if(p==1) mi=min(mi,abs(num-a[1]));
	else mi=min({mi,abs(num-a[p-1]),abs(num-a[p])});
	return ans;
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
		if(m==0) {
			int re=n-1;
			//		cout<<get()<<" -- "<<T+1<<"\n" ;
			int ans=re*re;
			int tmp=re/2;
			int ans2=tmp*tmp+(re-tmp)*(re-tmp);
			cout<<min(ans,ans2)<<"\n";
			continue;
		}
		int fo=find(1),fn=find(n);
		if(fo==fn) {
			cout<<"0\n";
			continue;
		}
		an=0,bn=0;
		for(int i=1; i<=n; i++) {
			if(find(i)==fo) a[++an]=i;
			if(find(i)==fn) b[++bn]=i;
		}
		sort(a+1,a+1+an);
		sort(b+1,b+1+bn);//提前排序
		int re=get();
//		cout<<get()<<" -- "<<T+1<<"\n" ;
		int ans=re*re;
		int tmp=re/2;
		int ans2=tmp*tmp+(re-tmp)*(re-tmp);
		int ans3=1e9;
		for(int i=2; i<=n-1; i++) {
			if(find(i)!=fo&&find(i)!=fn) {
				//计算
				ans3=min(ans3,ge(i)) ;
			}
		}
		cout<<min({ans,ans2,ans3})<<"\n";
	}
	return 0;
}