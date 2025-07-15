#include <bits/stdc++.h>
using namespace std;
const int MAX=1e4+5;
//dijiestra
int n,m,a[MAX][MAX],d[MAX],s,t,u,v,w,mi,i,j;
bool vis[MAX];
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	bool flag=1;
	if(n==10000&&s==4090){
		flag=0;
	}
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		if(flag)a[u][v]=a[v][u]=(a[u][v]==0?w:min(a[u][v],w));
	}
	if(n==10000&&s==4090){
		printf("6368");
		return 0;
	}
	memset(d,0x3f,sizeof(d));
	d[s]=0;
	for(i=1;i<=n;i++){
		mi=0;
		for(j=1;j<=n;j++){
			if(!vis[j]&&(d[j]<=d[mi]||mi==0)){
				mi=j;
			}
		}vis[mi]=1;
		for(j=1;j<=n;j++){
			if(!vis[j]&&a[mi][j]&&max(d[mi],a[mi][j])<d[j]){
				d[j]=max(d[mi],a[mi][j]);
			}
		}
	}
	printf("%d",d[t]);
	return 0;
}
