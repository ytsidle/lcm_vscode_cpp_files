#include <bits/stdc++.h>
using namespace std;
const int MAXF=1e4+10;
const int MAX=2e5+10;
int f[MAXF],n,m,z,x,y;
int find(int  xs){
	if(f[xs]==xs)return xs;
	return  f[xs]=find(f[xs]);
}//并查集
int main(){
	cin>>n>>m>>z;
	//初始化
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		
		//合并并查集
		f[find(x)]=find(y);
		
	}for(int i=1;i<=z;i++){
		cin>>x>>y;
		if(find(x)==find(y)){
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
	}
	return 0;
}
