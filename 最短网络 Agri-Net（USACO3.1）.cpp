#include <bits/stdc++.h>
using namespace std;
//kruska算法
struct node{
	int x,y,z;
}e[10010];
int n,bian,f[110],ans,k;
void build(int x,int y,int num){
	bian++;
	e[bian].x=x,e[bian].y=y,e[bian].z=num;
}bool cmp(node o,node t){
	return o.z<t.z;
}
int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
int main(){
	cin>>n;
	int tx;
	for(int i=1;i<=n;i++){
		f[i]=i;
		for(int j=1;j<=n;j++){
			cin>>tx;
			if(i<j&&tx!=0) build(i,j,tx);
		}
	}
	sort(e+1,e+1+bian,cmp);
	for(int i=1;i<=bian;i++){
		int  fx=find(e[i].x),fy=find(e[i].y);
		if(fx!=fy){
			ans+=e[i].z;
			f[fy]=fx;
			k++;
			if(k==n-1) break;
		}
	}cout<<ans;
	return 0;
}
