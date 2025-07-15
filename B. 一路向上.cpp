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
	return a.h<b.h;
}
int n,m,a[MAX],c[MAX],k,ans=1;
inline int exc(int i,int j){
	return (i-1)*m+j;
}

//bool vis[MAX][MAX];
int fx[5]={0,-1,0,1,0};
int fy[5]={0,0,1,0,-1};

int main(){
//	freopen("up.in","r",stdin);
//	freopen("up.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
//			vis[i][j]=1;
			scanf("%d",&a[exc(i,j)]);
			points[++k]={i,j,a[exc(i,j)]};
		}
	}
	sort(points+1,points+1+k,cmp);
	for(int i=1;i<=k;i++){
		Point now=points[i];
		int np=exc(now.x,now.y);
		for(int i=1;i<=4;i++){
			int tx=now.x+fx[i],ty=now.y+fy[i],p=exc(tx,ty);
			if(a[np]>a[p]){
				c[np]=max(c[np],c[p]+1);
			}
		}
		ans=max(ans,c[np]);
		

	}
	printf("%d",ans);
	return 0;
}
