#include <bits/stdc++.h>
using namespace std;
int w,h,sx,sy,ex,ey;
char c[3000][3000];
int dp[3000][3000];
int fx[5]={0,-1,0,1,0};
int fy[5]={0,0,1,0,-1};
bool vis[3000][3000];
int main(){
	cin>>h>>w;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cin>>c[i][j];
		}
	}
	cin>>sx>>sy>>ex>>ey;
	memset(dp,0x3f,sizeof(dp));
	queue<pair<int,int> > q;
	q.push({sx,sy});
	dp[sx][sy]=0;
	while(!q.empty()){
		int nx=q.front().first,ny=q.front().second;
		for(int i=1;i<=4;i++){
			int tx=nx+fx[i],ty=ny+fy[i];
			if(tx>=1&&tx<=h&&ty>=1&&ty<=w&&dp[tx][ty]>dp[nx][ny]){
				if(c[tx][ty]=='.'){
					q.push({tx,ty});
					dp[tx][ty]=dp[nx][ny];
				}else{
					if(c[nx+2*fx[i]][ny+2*fy[i]]=='.'||(nx+2*fx[i]>=1&&nx+2*fx[i]<=h&&ny+2*fy[i]>=1&&ny+2*fy[i]<=w)==0)q.push({tx,ty});
					else q.push({nx+2*fx[i],ny+2*fy[i]});
					dp[tx][ty]=min(dp[tx][ty],dp[nx][ny]+1);
					dp[nx+2*fx[i]][ny+2*fy[i]]=min(dp[nx][ny]+1,dp[nx+2*fx[i]][ny+2*fy[i]]);
				}
			}
		}
		q.pop();
		vis[nx][ny]=0;
	}
	cout<<dp[ex][ey];
	return 0;
}
