#include <bits/stdc++.h>
using namespace std;
const int MAX=55;
bool a[MAX][MAX]={};
int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		a[i][i]=1;
		a[i][n-i+1]=1;
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j])cout<<'+';
			else cout<<'-';
		}cout<<endl;
	}
	return 0;
}
