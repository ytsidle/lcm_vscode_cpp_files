#include <bits/stdc++.h>
using namespace std;
const int MAX=15,INF=0x3f3f3f3f;
int d[MAX],n,m,a[MAX][MAX],x,y,len;
bool vis[MAX];
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>len;
		a[x][y]=a[y][x]=len;
	}
	cin>>x>>y;
	memset(d,0x3f,sizeof(d));
	d[x]=0;
	for(int i=1;i<=n;i++){
		int mi=0;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&(mi==0 || d[j]<d[mi])) mi=j;
		}
		vis[mi]=1;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&a[mi][j]+d[mi]<d[j]&&a[mi][j]){
				d[j]=a[mi][j]+d[mi];
			}
		}
	}
	if(d[y]==INF){
		cout<<"No path";
		return 0;
	}
	cout<<d[y];
	return 0;
}
