#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
//dijastra
struct data{
	int v,p,next;
}edge[25050];
int n,m,q,u,v,p,s,e,pre[330],k,a[330][330];
int d[330];
bool vis[330],dos[330];
void add(int u,int v,int p){
	edge[++k]={v,p,pre[u]};
	pre[u]=k;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&p);
		add(u,v,p);
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&s,&e);
		if(dos[s]){
			if(a[s][e]==INF){
				printf("-1\n");
			}else printf("%d\n",a[s][e]);
			continue;
		}
		memset(d,0x3f,sizeof(d));
		memset(vis,0,sizeof(vis));
		d[s]=0;
		a[s][s]=0;
		for(int i=1;i<=n;i++){
			int mp=0;
			for(int j=1;j<=n;j++){
				if(!vis[j]&&(mp==0||d[j]<d[mp])) mp=j;
			}
			vis[mp]=1;

			for(int  j=pre[mp];j;j=edge[j].next){
				int ejp=edge[j].p,ejv=edge[j].v;
				if(max(d[mp],ejp)<d[ejv]){
					d[ejv]=max(d[mp],ejp);
					a[s][ejv]=d[ejv];
				}
			}
		}
		if(d[e]!=INF) printf("%d\n",d[e]);
		else printf("-1\n");
		dos[s]=1;
	}
	return 0;
}
