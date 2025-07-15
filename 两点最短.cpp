#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
struct data{
	int x,y;
}da[110];
int n,m,x,y,s,t;
double d[110],a[110][110];
bool vis[110];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&da[i].x,&da[i].y);
	}scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		double len=sqrt(abs(da[x].x-da[y].x)*abs(da[x].x-da[y].x)+abs(da[x].y-da[y].y)*abs(da[x].y-da[y].y));
		a[x][y]=a[y][x]=len;
	}
	scanf("%d%d",&s,&t);
	memset(d,0x3f,sizeof(d));
	d[s]=0;
	for(int i=1;i<=n;i++){
		int mi=0;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&(mi==0 || d[j]<d[mi])){
				mi=j;
			}
		}
		vis[mi]=1;
		for(int j=1;j<=n;j++){
			if(a[mi][j]&&!vis[j]&&d[mi]+a[mi][j]<=d[j]){
				d[j]=d[mi]+a[mi][j];
			}
		}
	}
//	printf("%.2f",d[t]);
cout<<d[t];
	return 0;
}
