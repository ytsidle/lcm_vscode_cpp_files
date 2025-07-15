#include <bits/stdc++.h>
using namespace std;
int a[410][410],n,m,x,y,q[410*401][3],qn,ti,tj,h,e;
//马走日
int dj[9]={0,2,1,-1,-2,2,1,-1,-2};
int di[9]={0,-1,-2,-2,-1,1,2,2,1};
void bfs(int i,int j){
	a[i][j]=-2;
	qn++,h++;
	q[h][0]=i,q[h][1]=j,q[h][3]=0;
	while(h<=qn){
		//遍历附近点,加入队列
//		bool type=false;
		for(int i=1;i<=8;i++){
			ti=q[h][0]+di[i],tj=q[h][1]+dj[i];
			if(ti<=m&&tj<=n&&ti>0&&tj>0&&a[ti][tj]==0){
				qn++;
				q[qn][0]=ti,q[qn][1]=tj,q[qn][2]=q[h][2]+1;
				a[ti][tj]=q[qn][2];
//				a[ti][tj]=q[qn][2];
			}
		}//根据队列设置
		h++;
//		a[q[h][0]][q[h][1]]=q[h][2];
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&x,&y);
	bfs(x,y);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==-2) a[i][j]=0;
			else if(a[i][j]==0) a[i][j]=-1;
			printf("%-5d",a[i][j]);
		}cout<<"\n";
	}
	return 0;
}
