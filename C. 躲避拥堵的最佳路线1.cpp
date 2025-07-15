#include <bits/stdc++.h>
using namespace std;
const int M=2e4+10;
//kruskal 轻松搞掂
struct Data{
	int u,v,w;
}data[M];
int n,f[M],m,s,t;
bool cmp(Data a,Data b) {
	return a.w<b.w;
}
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void mer(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		f[fy]=fx;
	}
}

int main(){
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++){
		cin>>data[i].u>>data[i].v>>data[i].w;
	}
	sort(data+1,data+1+m,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int fx=find(data[i].u),fy=find(data[i].v),fw=data[i].w;
		if(fx!=fy){
			mer(fx,fy);
			if(find(s)==find(t)){
				cout<<fw;
				break;
			}
		}
	}
	return 0;
}
