#include <bits/stdc++.h>
using namespace std;
int n,m,a[110][110],num;
int fi[5]={0,-1,0,0,1};
int fj[5]={0,0,-1,1,0};
void dfs(int x,int y){
	a[x][y]=++num;
	for(int i=1;i<=4;i++){
		int ti=x+fi[i],tj=y+fj[i];
		if(ti>=1&&ti<=n&&tj>=1&&tj<=m&&a[ti][tj]==0) dfs(ti,tj);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]==1) a[i][j]=-1;
		}
	}dfs(1,1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			
			if(a[i][j]==-1) printf("%d ",0);
			else printf("%d ",a[i][j]);
		}cout<<endl;
	}
	return 0;
}
