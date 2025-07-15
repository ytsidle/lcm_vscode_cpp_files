#include <bits/stdc++.h>
using namespace std;
int n,a,b;
int jiou[1010][1010],ans;
int vis[1010][1010];
char c[1100][1100];
int dfs(int x,int y,int  cc){
	vis[x][y]=1;
	if(cc==1&&c[x][y]=='G') ans--;
	int tx=x-b,ty=y-a;
	if(tx<=0||tx>n||ty<=0||ty>n||vis[tx][ty]){
		return 0;
	}
	return dfs(tx,ty,(~cc));
}
int dfs2(int x,int y,int  cc){
	vis[x][y]=1;
	if(cc==1&&c[x][y]=='G') ans--;
	int tx=x+b,ty=y+a;
	if(tx<=0||tx>n||ty<=0||ty>n||vis[tx][ty]){
		return 0;
	}
	return dfs2(tx,ty,(~cc));
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>a>>b;
		int flag=0;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>c[i][j];
				if(c[i][j]=='B'){
					ans++;
					int ti=i-b;
					int tj=j-a;
					if((ti<=0||ti>n||tj<=0||tj>n)&&0){
						flag=1;
					}else{
						if(c[ti][tj]=='W'){
							flag=1;
						}
					}
				}if(c[i][j]=='G'){
					ans++;
				}
			}
		}
		if(flag){
			cout<<-1<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(c[i][j]=='B'){
					memset(vis,0,sizeof(vis));
					jiou[i][j]=1;
					int re=dfs(i,j,0);
					if(re==-1) flag=1;
					jiou[i][j]=2;
					re=dfs2(i,j,1);
					if(re==-1) flag=1;
					if(flag) break;
				}
			}if(flag) break;
		}
		if(flag){
			cout<<-1<<endl;
			continue;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
