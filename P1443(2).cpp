#include <bits/stdc++.h>
#include <queue>
using namespace std;
//STL版本
struct horse{
	int x,y,t;
};
queue<horse> que;
int n,m,x,y,a[410][410];
int dx[8]={-2,-2,-1,-1,2,2,1,1};
int dy[8]={1,-1,2,-2,1,-1,2,-2};
int main(){
	memset(a,-1,sizeof(a));
	scanf("%d%d%d%d",&n,&m,&x,&y);
	a[x][y]=0;
	que.push((horse){x,y,0});
	while(!que.empty()){
		horse f=que.front();
		que.pop();
		for(int i=0;i<8;i++){
			int tx=f.x+dx[i],ty=f.y+dy[i];
			if(tx>=1&&ty>=1&&tx<=n&&ty<=m&&a[tx][ty]==-1){
				a[tx][ty]=f.t+1;
				que.push((horse){tx,ty,f.t+1});
			}
		}
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%-5d",a[i][j]);
		}printf("\n");
	}
		
	return 0;
}
