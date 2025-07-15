#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
//链式前向星
long long pre[MAX],n,m,s,tf,ts,k,d[MAX],ds[MAX];
bool vis[MAX];
long long ans;
struct Node{
	long long v,l,next;
}nodes[4*MAX];
inline void add(long long u,long long v,long long l){
	nodes[++k]={v,l,pre[u]};
	pre[u]=k;
}
int main(){
	scanf("%d%d%d%d%d",&m,&n,&s,&tf,&ts);
	for(int i=1;i<=m;i++){
		long long u,v,l;
		scanf("%d%d%d",&u,&v,&l);
		add(u,v,l);
		add(v,u,l);
	}
	//dijiestra
	memset(d,0x3f,sizeof(d));
	d[s]=0;
	for(int i=1;i<=n;i++){
		int mi=0;
		for(int j=1;j<=n;j++){
			if((mi==0||d[j]<d[mi])&&!vis[j]){
				mi=j;
			}
		}
		vis[mi]=1;
		for(int j=pre[mi];j;j=nodes[j].next){
			if(!vis[nodes[j].v]&&(d[mi]+nodes[j].l<d[nodes[j].v])){
				d[nodes[j].v]=d[mi]+nodes[j].l;
			}
		}
	}
	//----d2
	memset(ds,0x3f,sizeof(ds));
	memset(vis,0,sizeof(vis));
	ds[tf]=0;
	for(int i=1;i<=n;i++){
		int mi=0;
		for(int j=1;j<=n;j++){
			if((mi==0||ds[j]<ds[mi])&&!vis[j]){
				mi=j;
			}
		}
		vis[mi]=1;
		for(int j=pre[mi];j;j=nodes[j].next){
			if(!vis[nodes[j].v]&&(ds[mi]+nodes[j].l<ds[nodes[j].v])){
				ds[nodes[j].v]=ds[mi]+nodes[j].l;
			}
		}
	}
	printf("%lld",min((d[tf]+ds[ts]),(d[ts]+ds[ts])));
	return 0;
}
