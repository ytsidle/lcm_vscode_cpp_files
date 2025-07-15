#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int n,m;
ull a[20][20],vis[20];
__int128 d[20];
void write(__int128 x) {
//	if (x < 0) {
//		x = -x;
//		putchar('-');
//	}
//	if (x > 9) write(x / 10);
//	putchar(x % 10 + '0');
	cout<<x;
}
int main(){
	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	cin>>n>>m;
	memset(a,-1,sizeof(a));
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=a[v][u]=w;
	}
	memset(d,0x3f,sizeof(d));
//	cout<<d[1];
	d[1]=0;
	for(int i=1;i<=n;i++){
		int mi=0;
		for(int j=1;j<=n;j++){
			if(d[j]<d[mi]&&vis[j]==0) mi=j;
		}
		vis[mi]=1;	
		for(int j=1;j<=n;j++){
			if(a[mi][j]!=-1ull){
				if(!vis[j]){
					d[j]=min(d[j],d[mi]^a[mi][j]);
				}
			}
		}
	}
	write(d[n]);
	return 0;
}
