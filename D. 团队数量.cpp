#include <bits/stdc++.h>
using namespace std;
const int M=2e4+10;
int n,m,f[M],num[M],k;
int find(x){
	return f[x]==x?x:f[x]=find(f[x]);
}
vector<int> v;
void mer(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		f[fx]=fy;
		num[fy]+=num[fx];
		num[fx]=0;
	}
}
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i,num[i]=1;
	for(int i=1;i<=k;i++){
		int x,y;
		cin>>x>>y;
		mer(x,y);
	}
	//两种方法
	for(int i=1;i<=n;i++){
		if(num[i]!=0){
			v.push_back(num[i]);
		}
	}sort(v.begin(),v.end());
	return 0;
}
