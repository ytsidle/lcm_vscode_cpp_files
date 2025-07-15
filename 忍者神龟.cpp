#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
//dijastra
int a[330][330],n,m,q,u,v,p,s,e;
int d[330];
bool vis[330];
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&p);
		a[u][v]=p;
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&s,&e);
		memset(d,0x3f,sizeof(d));
		memset(vis,0,sizeof(vis));
		d[s]=0;
		for(int i=1;i<=n;i++){
			int mp=0;
			for(int j=1;j<=n;j++){
				if(!vis[j]&&(mp==0||d[j]<d[mp])) mp=j;
			}
			vis[mp]=1;
			for(int j=1;j<=n;j++){
				if(a[mp][j]){
					if(max(d[mp],a[mp][j])<d[j]) d[j]=max(d[mp],a[mp][j]);
				}
			}
		}
		if(d[e]!=INF) printf("%d\n",d[e]);
		else printf("-1\n");
	}
	return 0;
}
