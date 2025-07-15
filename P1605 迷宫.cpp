#include <bits/stdc++.h>
using namespace std;
int n,m,t,a[7][7],sx,sy,fx,fy,te,te1,ans;
int dx[5]={0,0,0,1,-1};//打表；
int dy[5]={0,-1,1,0,0};
void dfs(int x,int y){
	if(x==fx&&y==fy){
		ans++;
		return;
	}for(int i=1;i<=4;i++){
		int tx=x+dx[i],ty=y+dy[i];
		a[x][y]=2;
		if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]==0){
			
			dfs(tx,ty);
			a[tx][ty]=0;
		}
	}
}
int main(){
	cin>>n>>m>>t>>sx>>sy>>fx>>fy;
	for(int i=1;i<=t;i++){
		scanf("%d%d",&te,&te1);
		a[te][te1]=1;
	}
	dfs(sx,sy);
	cout<<ans;
	return 0;
}
