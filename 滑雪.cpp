#include <bits/stdc++.h>
using namespace std;
int dp[150][150],r,c,h[150][150],ans=1;
struct point{
	int x,y,high;
}points[15000];
bool cmp(point a,point b){
	return a.high<b.high;
}
int fx[5]={0,-1,0,1,0};
int fy[5]={0,0,1,0,-1};
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>r>>c;
	int k=0;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			cin>>points[++k].high;
			h[i][j]=points[k].high;
			points[k].x=i;
			points[k].y=j;
		}
	}
	sort(points+1,points+1+k,cmp);
	for(int i=1;i<=k;i++){
		int nx=points[i].x,ny=points[i].y;
		// if(points[i].high==points[i-1].high) continue;
		for(int j=1;j<=4;j++){
			int tx=nx+fx[j],ty=ny+fy[j];
			if(h[tx][ty]<h[nx][ny]){
				dp[nx][ny]=max(dp[tx][ty]+1,dp[nx][ny]);
			}
		}ans=max(ans,dp[nx][ny]);
	}
	cout<<ans;
	return 0;
}
