#include<bits/stdc++.h>
using namespace std;
int x,y,z,n,m,s,t;
double a[2010][2010],d[2010];
bool f[2010];
queue<int> q;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		a[x][y]=a[y][x]=1-(0.01*z);
	}
	scanf("%d%d",&s,&t);
	d[s]=1;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		f[u]=1;
		for(int i=1;i<=n;i++){
			if(a[u][i]>0&&d[u]*a[u][i]>d[i]){
				d[i]=d[u]*a[u][i];
				f[i]=1;
				q.push(i);
			}
		}
		q.pop();
		f[u]=0;
	}
	printf("%.8f",100/d[t]);
	return 0;
}