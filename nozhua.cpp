#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int fi[5]={0,-1,0,0,1};
int fj[5]={0,0,-1,1,0};
char t,a[510][510];
void dfs(int x,int y){
	a[x][y]='y';
	for(int i=1;i<=4;i++){
		int ti=x+fi[i],tj=y+fj[i];
		if(ti>=1&&ti<=n&&tj>=1&&tj<=m&&a[ti][tj]=='0') dfs(ti,tj);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}for(int i=1;i<=n;i++){
		if(i==1||i==n){
			for(int j=1;j<=m;j++){
				if(a[i][j]=='0') dfs(i,j);
			}
		}else{
			if(a[i][1]=='0') dfs(i,1);
			if(a[i][m]=='0') dfs(i,m);
		}
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
//			cout<<a[i][j]<<" ";
			if(a[i][j]=='0') ans++;
		}
	}cout<<ans;
	return 0;
}
