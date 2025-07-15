#include <bits/stdc++.h>
using namespace std;
char s[100][100],t[100][100];
int n,m;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cin>>s[i][j];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cin>>t[i][j];
		}
	}
	int l=n-m+1;
	for(int a=1;a<=l;a++){
		for(int b=1;b<=l;b++){
			int flag=1;
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					if((s[a+i-1][b+j-1]==t[i][j])==0){
						flag=0;
						break;
					} 
				}if(!flag) break;
			}
			if(flag){
				cout<<a<<" "<<b;
				return 0;
			}
		}
	}
	return 1;
}
