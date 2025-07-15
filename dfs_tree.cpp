#include <bits/stdc++.h>
using namespace std;
int a[1100][1100],n;
char c[1100][1100];
void dfs(int num,int father){
	printf("%d ",num);
	for(int i=1;i<=n;i++){
		if(i!=num&&i!=father&&a[num][i]!=0){
			dfs(i,num);
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
//			scanf("%c",&c[i][j]);
			cin>>c[i][j];
			a[i][j]=c[i][j]-'0';
		}
	}dfs(1,0);
	return 0;
}
