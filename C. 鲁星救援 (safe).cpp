#include <bits/stdc++.h>
using namespace std;
const int MAX=1e3+10;
//先求出鬼才的路线
//再bfs Luke的路线
//当相遇时,若满足条件,输出步数
//成功结束,没退出输出
int a[MAX][MAX],c[MAX][MAX],n, m, sx, sy, tx, ty, px, py,b[MAX][MAX],d[MAX][MAX];
pair<int,int> gf[MAX][MAX];
bool vis[MAX][MAX];
int fj[5]={0,0,1,0,-1};
int fi[5]={0,-1,0,1,0};
void dfs(int i,int j){
	if(i==0&&j==0) return;
	vis[i][j]=1;
	dfs(gf[i][j].first,gf[i][j].second);
//	cout<<i<<" "<<j<<endl;
}
int main(){
	freopen("safe.in","r",stdin);
	freopen("safe.out","w",stdout);
	scanf("%d%d%d%d%d%d%d%d",&n,&m,&sx,&sy,&tx,&ty,&px,&py);//s,t,p:鬼才、家门、地道
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			d[i][j]=a[i][j];
		}
	}
	if(a[px][py]==1) {
		printf("%d",-1);
		exit(0);
	}
	queue<pair<int,int> > q;
	q.push({sx,sy});
	a[sx][sy]=1;
	while(!q.empty()){
		int ni=q.front().first,nj=q.front().second;
		q.pop();
		for(int i=1;i<=4;i++){
			int ti=ni+fi[i],tj=nj+fj[i];
			if(ti>=1&&ti<=n&&tj<=n&&tj>=1&&!a[ti][tj]){
				q.push({ti,tj});
				a[ti][tj]=1;
				b[ti][tj]=b[ni][nj]+1;
				gf[ti][tj]={ni,nj};
				if(ti==px&&tj==py){
					break;
				}
			}
		}
	}
	if(a[px][py]!=1){
		printf("-1");
		exit(0);
	}
	dfs(px,py);
	q.push({tx,ty});
	d[tx][ty]=1;
	while(!q.empty()){
		int ni=q.front().first,nj=q.front().second;
		q.pop();
		for(int i=1;i<=4;i++){
			int ti=ni+fi[i],tj=nj+fj[i];
			if(ti>=1&&ti<=n&&tj<=n&&tj>=1&&!d[ti][tj]){
				q.push({ti,tj});
				d[ti][tj]=1;
				c[ti][tj]=c[ni][nj]+1;
				if(vis[ti][tj]){
//					cout<<ti<<" "<<tj<<endl;
					printf("%d",c[ti][tj]);
					exit(0);
				}
			}
		}
	}
	printf("-1");
	return 0;
}
