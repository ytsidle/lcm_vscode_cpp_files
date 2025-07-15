#include <bits/stdc++.h>
using namespace std;
char s[1500][1500];
int rol[2500][2500],col[2500][2500],n,m;//rol竖直,col横着
long long ans=0;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>s[i][j];
			if(s[i][j]=='v'){
				col[i][j]=col[i][j-1]+1;
				rol[i][j]=rol[i-1][j]+1;
				ans+=1ll*(col[i][j]-1)*(rol[i-1][j]-1);
			}
		}
	}
	cout<<ans;
	return 0;
}
