#include <bits/stdc++.h>
using namespace std;
const int  MAX_N=1e4+10,N=1050;
//#define long long  int
struct Edge{
	int x,y,z;
}e[2*MAX_N];
int f[N],k,sum,n,m;
bool cmp(Edge a,Edge b){
	return a.z<b.z;
}
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
int kks;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> m >> kks;
	for(register int i=1;i<=n;i++) f[i]=i;
	for(register int i=1;i<=m;i++){
		cin>>e[i].x>>e[i].y>>e[i].z;
	}
	sort(e+1,e+1+m,cmp);
	for(register int i=1;i<=m;i++){
		register int fx=find(e[i].x),fy=find(e[i].y);
		if(fx!=fy){
			f[fx]=fy;
			k++;
			sum+=e[i].z;
			if(k==n-kks) {
				cout<<sum;
				return 0;
			}
		}
	}
	cout<<"No Answer";
	return 0;
}