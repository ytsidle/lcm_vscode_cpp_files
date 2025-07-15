#include <bits/stdc++.h>
using namespace std;
//prim算法
int n,m,a,b,c,g[5010][5010],minn[5010],sum;//g用邻接矩阵,不存在超大数
//minn[i]表示未加入树的点i到加入最小生成树的节点的距离
bool u[5010];
int main(){
	memset(g,0x7f,sizeof(g));
	memset(minn,0x7f,sizeof(minn));
	memset(u,1,sizeof(u));//初始化
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		g[a][b]=g[b][a]=c;
	}
	minn[1]=0;
	for(int i=1;i<=n;i++){
		int k=0;
		for(int j=1;j<=n;j++){
			if(u[j]&&minn[j]<minn[k]){
				k=j;
			}
		}//k加入生成树
		u[k]=0;
		sum+=minn[k];
		//通过k刷新minn
		for(int j=1;j<=n;j++){
			if(u[j]&&g[k][j]<minn[j]){
				minn[j]=g[k][j];
			}
		}
	}int tot=0;
	printf("%d",sum);
	return 0;
}
