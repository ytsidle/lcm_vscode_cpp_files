#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+10;
//bfs可行性
/*
	o(n*m^2)
	2e6<1e8;
*/
struct Point{
	int x,y,h;
}points[MAX];
bool cmp(Point a,Point b){
	return a.h>b.h;
}
int n,m,a[MAX][MAX],c[MAX][MAX],k,ans=1;
bool vis[MAX][MAX];
int fx[5]={0,-1,0,1,0};
int fy[5]={0,0,1,0,-1};
void bfs(Point st){
	queue<pair<int,int> > q;
	memset(c,0,sizeof(c));
	q.push({st.x,st.y});
	c[st.x][st.y]=1;
	while(!q.empty()){
		int hx=q.front().first,hy=q.front().second;
		q.pop();
		for(int i=1;i<=4;i++){
			int tx=hx+fx[i],ty=hy+fy[i];
			if(a[hx][hy]>=a[tx][ty]&&vis[tx][ty]){
				c[tx][ty]=c[hx][hy]+1;
				ans=max(ans,c[tx][ty]);
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			vis[i][j]=1;
			scanf("%d",&a[i][j]);
			points[++k]={i,j,a[i][j]};
		}
	}
	sort(points+1,points+1+k,cmp);
	for(int i=1;i<=n;i++){
		Point now=points[i];
		bfs(now)
	}
	return 0;
}
