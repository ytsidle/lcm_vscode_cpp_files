#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M=2e6+10;
struct Edge{
	int u,v,w;
	bool operator<(const Edge & b) const{
		return w<b.w;
	}
}e[M];
int l,r,f[M],vis[M],k;
int lcm(int x,int y){
	return x/__gcd(x,y)*y;
}
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>l>>r;
	for(int i=1;i<=l;i++) f[i]=i;
	for(int i=l;i<=r;i++)  f[i]=i,vis[i]=1;
	for(int i=2;i<=r;i++){
		int cnt=0,fis=0;
		for(int j=i;j<=r;j+=i){
			if(vis[j]&&fis==0) fis=j;
			else if(vis[j]) e[++k]={fis,j,lcm(fis,j)};
		}
		if(i>=l) e[++k]={l,fis,lcm(l,fis)};
	}
//	cout<<k<<endl;
	sort(e+1,e+1+k);
	int ans=0;
	for(int i=1;i<=k;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)!=find(v)){
			f[find(u)]=find(v);
			ans+=w;
		}
	}cout<<ans;
	return 0;
}