#include <bits/stdc++.h>
using namespace std;
int n,m,c,a[505][505],si,sj;
char t;		
int fx[5]={0,0,1,0,-1};
int fy[5]={0,1,0,-1,0};
int que[505*505][3];
int main(){
	cin>>n>>m>>c;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>t;
			if(t=='#') a[i][j]=-1;
			if(t=='S'){
				a[i][j]=-2;
				si=i,sj=j;
			}if(t=='E'){
				a[i][j]=-3;
			}
		}
	}

	int h=0,e=0;
	que[h][0]=si,que[h][1]=sj;
	
	while(h<=e){
	
		for(int i=1;i<=4;i++){
			int ti=que[h][0]+fy[i],tj=que[h][1]+fx[i];
			if(ti>=1&&tj>=1&&ti<=m&&tj<=n&&a[ti][tj]!=-1&&a[ti][tj]!=-2){
				e++;
				que[e][0]=ti,que[e][1]=tj,que[e][2]=que[h][2]+1;
				if(a[ti][tj]==-3){
					cout<<(que[e][2])*c<<endl; 
					return 0;
				}
				a[ti][tj]=que[e][2];
				
			}
		}h++; 

	}
	cout<<-1;
	
	return 0;
}
