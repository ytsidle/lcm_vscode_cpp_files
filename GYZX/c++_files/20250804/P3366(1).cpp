#include <bits/stdc++.h>
using namespace std;
const int  MAX_N=2e5+10,N=5050;;
struct Edge{
	long long x,y,z;
}e[2*MAX_N];
long long f[N],k,sum,n,m;
bool cmp(Edge a,Edge b){
	return a.z<b.z;
}
long long find(long long x){
	return f[x]==x?x:f[x]=find(f[x]);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>e[i].x>>e[i].y>>e[i].z;
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		int fx=find(e[i].x),fy=find(e[i].y);
		if(fx!=fy){
			f[fx]=fy;
			k++;
			sum+=e[i].z;
			if(k==n-1) break;
		}
	}
	if(k<n-1){
		cout<<"orz";
	}else cout<<sum;
	return 0;
}