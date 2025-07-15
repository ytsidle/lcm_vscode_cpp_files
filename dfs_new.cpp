#include <bits/stdc++.h>
using namespace std;
int n,m,a[200][200],cn;
void dfs(int x,int y,int num){
	//赋值
	a[x][y]=++cn; 
	//up
	if(x-1>=1 && a[x-1][y] == 0) dfs(x-1,y,num+1);
		//left
	if(y-1>=1 && a[x][y-1] == 0) dfs(x,y-1,num+1);
	//right
	if(y+1<=m && a[x][y+1] == 0) dfs(x,y+1,num+1);
	//down
	if(x+1<=n && a[x+1][y] == 0) dfs(x+1,y,num+1);

	
}
int main(){
	cin>>n>>m;
	for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 1) a[i][j] = -1;
        }
    }
	dfs(1,1,1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==-1) a[i][j]=0;
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}