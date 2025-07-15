#include <bits/stdc++.h>
using namespace std;
//bfs重复走2^x步,标记为i;

int n,m;
char a[1100][1100];
int h=1,t=1;
int r[1010*1010][4]={};
int fx[5]={0,0,1,0,-1};
int fy[5]={0,1,0,-1,0};
bool flag=0;
void bfs(int x,int y){
	r[1][0]=x,r[1][1]=y,r[1][2]=0;
	//x表i,y表j
    char yuan=a[x][y];
    a[x][y]='X';
	if(yuan=='#') {
		flag=1;return;
	}
	while(h<=t){
		for(int i=1;i<=4;i++){
			for(int j=1;j<=max(n,m);j*=2){
				int tx=r[h][0]+fx[i]*j,ty=r[h][1]+fy[i]*j;
				if(tx>=1 && ty>=1 && tx<=n && ty<=m && (a[tx][ty]!='X')){
					
					
					t++;
					r[t][0]=tx;
					r[t][1]=ty;
					r[t][2]=r[h][2]+1;
					if(a[tx][ty]=='#'){
						flag=1;return;
					} 
					a[tx][ty]='X';
				}
			}
		}h++;
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}

	bfs(1,1);
//		for(int i=1;i<=t;i++){
//		for(int j=0;j<3;j++){
//			cout<<r[i][j]<<" ";
//		}cout<<endl;
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<a[i][j]<<" ";
//		}cout<<endl;
//	}
	if(flag) cout<<r[t][2];
	else cout<<-1;
	return 0;
}
