#include <bits/stdc++.h>
using namespace std;
const int MAX=2e5+10;
int n,m,c,f[MAX],cnt;
bool vis[MAX];
struct Node{
	int x,y;
}nodes[MAX];
inline int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
inline void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		f[fy]=fx;
	}
}
inline bool check(){
	int ans=0;
	if(cnt==1) return 1;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		if(!vis[nodes[i].x]&&!vis[nodes[i].y]){
			merge(nodes[i].x,nodes[i].y);
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]&&f[i]==i){
			ans++;
		}
		if(ans>=2 )return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	cnt=n;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&nodes[i].x,&nodes[i].y);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c);
		if(check()) printf("Y\n");
		else printf("N\n");
		vis[c]=1;
		cnt--;
	}
	return 0;
}
