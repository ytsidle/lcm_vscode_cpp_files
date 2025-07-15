#include <bits/stdc++.h>
using namespace std;
const int MAX=1e9+7;
int d[102][102],t,n,m;
short a[102][102];
bool f[104][104];
int main(){
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%u",&a[i][j]);
		}
	}
	queue<pair<short int,short int> > q;
	q.push({1,1});
	while(!q.empty()){
		short int nx=q.front().first,ny=q.front().second;
		f[nx][ny]=1;
		for(int i=nx+1;i<=n;i++){
			for(int j=ny+1;j<=m;j++){
				if(a[i][j]!=a[nx][ny]){
					q.push({i,j});
					f[i][j]=1;
					d[i][j]++;
					d[i][j]=d[i][j]%MAX;
				}
			}
		}
		f[nx][ny]=1;
		q.pop();
	}
	printf("%d",d[n][m]);
}