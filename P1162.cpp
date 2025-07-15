#include <bits/stdc++.h>
using namespace std;
int a[35][35],n;
int fx[5]={0,1,0,-1,0};
int fy[5]={0,0,1,0,-1};
int pos[1225][2],num;
void dfs(int i,int j){
	if(i>0&&j>0&&i<=n&&j<=n&&a[i][j]==0&&a[i][j]!=1){
		a[i][j]=-1;
//		cout<<i<<" "<<j<<endl;
		for(int x=1;x<=4;x++){
			dfs(i+fy[x],j+fx[x]);
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			
			scanf("%d",&a[i][j]);
			if((i==1||i==n)&&a[i][j]==0){
				num++;
				pos[num][0]=i,pos[num][1]=j;
			}else if((j==1||j==n)&&a[i][j]==0){
				num++;
				pos[num][0]=i,pos[num][1]=j;
			}
		}
	}
	for(int i=1;i<=num;i++){
		if(a[pos[i][0]][pos[i][1]]==0){
			dfs(pos[i][0],pos[i][1]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==-1){
				cout<<0<<" ";
			}else if(a[i][j]==0){
				cout<<"2"<<" ";
			}else{
				cout<<1<<" ";
			}
		}cout<<endl;
	}
	return 0;
}
