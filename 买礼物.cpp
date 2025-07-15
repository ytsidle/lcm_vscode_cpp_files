#include <bits/stdc++.h>
using namespace std;
struct edge{
	int x,y,z;
}edges[250010];
int a,b,tn,tot,ans,f[555];
void build(int i,int j,int num){
	edges[++tot].x=i,edges[tot].y=j,edges[tot].z=num;
}
bool cmp(edge as,edge bs){
	return as.z<bs.z;
}
int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
int main(){
	cin>>a>>b;
	f[0]=0;
	for(int i=1;i<=b;i++){
		for(int j=1;j<=b;j++){
			cin>>tn;
			if(tn!=0&&i<j) build(i,j,tn);
		}
		build(0,i,a);
		f[i]=i;
	}
	sort(edges+1,edges+1+tot,cmp);
	int sum=1,dians=1;
	while(sum<=tot&&dians<=b){
		int fx=find(edges[sum].x),fy=find(edges[sum].y);
		if(fx!=fy){
			//连边
			dians++;
			f[fy]=fx;
			ans+=edges[sum].z;
		}sum++;
	}cout<<ans;
	return 0;
}
