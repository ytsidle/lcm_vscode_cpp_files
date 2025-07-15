#include <bits/stdc++.h>
using namespace std;
const int M=1e3+10;
int n,m,T,k,sx,sy,d,cnt;
int fx[4]={0,1,0,-1},fy[4]={1,0,-1,0};
char c[M][M];
int main(){
	scanf("%d",&T);
	while(T--){
		memset(c,0,sizeof(c));
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&sx,&sy,&d);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c[i][j];
			}
		}
		c[sx][sy]='y';
		cnt=1;
		for(int i=1;i<=k+1;i++){
			if(c[sx][sy]=='.') cnt++,c[sx][sy]='y';
			int tx=sx+fx[d],ty=sy+fy[d];
			if(c[tx][ty]=='.'||c[tx][ty]=='y') sx=tx,sy=ty;
			else{
				d+=1;
				d%=4;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
