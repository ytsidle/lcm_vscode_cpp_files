#include <bits/stdc++.h>
using namespace std;
//djiestra
const int M=2e4+2000;
int a[M][M];
int n,m,s,t,u,v,w;
int d[M];
bool vis[M];
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		a[u][v]=a[v][u]=w;
	}
	memset(d,0x3f,sizeof(d));
	memset(vis, 0, sizeof(vis));
	d[s]=0;
//	vis[s]=1;
	for(int i=1;i<=n;i++){
		int mi=0;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&d[j]<d[mi]) mi=j;
		}vis[mi]=1;
		for(int j=1;j<=n;j++){
			if(a[mi][j]&&!vis[j]){
				if(max(d[mi],a[mi][j])<d[j]) d[j]=max(d[mi],a[mi][j]);
			}
		}
		
	}
	printf("%d",d[t]);
	return 0;
}
