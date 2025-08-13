#include <bits/stdc++.h>
using namespace std;
int g[400][400],n,d[400],vis[400],sum;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		g[0][i]=g[i][0]=x;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cin>>g[i][j];
	}
	//prim
	memset(d,0x3f,sizeof(d));
	d[0]=0;
	for(int i=1;i<=n+1;i++){
		int u=INT_MAX;
		for(int j=0;j<=n;j++){
			if(!vis[j]){
				if(u==INT_MAX||d[j]<d[u]) u=j;
			}
		}
		if(u==INT_MAX) return 0;
		sum+=d[u];
		vis[u]=1;
		for(int j=0;j<=n;j++){
			if(g[u][j]){
				d[j]=min(d[j],g[u][j]);
			}
		}
	}cout<<sum;
	return 0;
}