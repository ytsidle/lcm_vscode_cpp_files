#include <bits/stdc++.h>
using namespace std;
const int MAX=1e4+10;
struct Edge{
	int x,y,l;
}edge[MAX];
int n,f[1010],m,k,cnt,sum,nto;
bool cmp(Edge a,Edge b){
	return a.l<b.l;
}
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>edge[i].x>>edge[i].y>>edge[i].l;
	}
	for(int i=1;i<=n;i++) f[i]=i;
	sort(edge+1,edge+1+m,cmp);
	nto=n;
	for(int i=1;i<=m;i++){
		int fx=find(edge[i].x),fy=find(edge[i].y);
		if(fx!=fy){
			nto--;
			cnt++;
			sum+=edge[i].l;
			f[fy]=fx;
		}
		if(nto==k) break;
	}
	if(nto!=k) cout<<"No Answer";
	else cout<<sum;
	return 0;
}
