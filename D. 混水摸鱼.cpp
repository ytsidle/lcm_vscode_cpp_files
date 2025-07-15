#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second.first
#define rd second.second
const int M=1e6+10;
int n,m,k,sx,sy,tx,ty;
int fx[5]={0,-1,0,1,0};
int fy[5]={0,0,1,0,-1};
char c[1000][1000];
int vis[1000][1000];
int main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	cin>>sx>>sy>>tx>>ty;
//	vector<char> tmp(m+10);
//	vector<vector <char> > c(n+10,tmp);
//	vector<int> tmps(m+10,0);
//	vector<vector <int> > vis(n+10,tmps);
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c[i][j];
		}
	}
	if(c[sx][sy]=='@'||c[tx][ty]=='@'){
		cout<<-1;
		exit(0);
	}
	pair<int,pair<int,int> > q[M];
	int head=1,tail=0;
//	q[++tail]={sx,{sy,0}};
//	vis[sx][sy]=0;
//	while(head<=tail){
//		for(int i=1;i<=4;i++){
//			if(i!=q[head].rd){
//				int tmpx=q[head].st+fx[i],tmpy=q[head].nd+fy[i];
//				int tot=1;
//				while(c[tmpx][tmpy]!='@'&&vis[tmpx][tmpy]==0){
//					vis[tmpx][tmpy]=vis[q[head].st][q[head].nd]+ceil(tot*1.0/k);
//					q[++tail]={tmpx,{tmpy,i}};
//					tmpx+=fx[i],tmpy+=fy[i];
//				}
//			}
//		}head++;
//	}if(vis[tx][ty]==0)cout<<-1;
//	else cout<<vis[tx][ty];
	return 0;
}
