#include <bits/stdc++.h>
using namespace std;
const int MAX=1e7+10;
struct Edge{
	int x,y,v;
//	bool operator < (const Edge &b) const
//	{
//		return v<b.v;
//	} 
}edge[MAX];
bool cmp(Edge a,Edge b){
	return a.v<b.v;
}
int n,f[1100],a[1100],c[1100][1100],k;

int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int x,int y){
	f[y]=x;
//	find(y);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		f[i]=i;
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&c[i][j]);
			for(int i=1;i<=a[i];i++)edge[++k]={i,j,c[i][j]};
		}
	}
	sort(edge+1,edge+1+k,cmp);
	int cnt=0;
	long long sum=0;
	for(int i=1;i<=k;i++){
		if(cnt==n-1){
			printf("%lld",sum);
			return 0;
		}
		int fx=edge[i].x,fy=edge[i].y;
		fx=find(fx),fy=find(fy);
		if(fx!=fy){
			merge(fx,fy);
			cnt++;
			sum+=edge[i].v;
		}
	}
	return 0;
}
