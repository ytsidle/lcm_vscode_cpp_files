#include <bits/stdc++.h>
using namespace std;
const int MAX=4e4+10;
int f[MAX],n,m,q,p,x,y;
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
	scanf("%d%d%d%d",&n,&m,&p,&q);
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	
	for(int i=1;i<=m;i++){
		f[n+i]=n+i;
	}
	mer(1,1);
	for(int i=1;i<=p;i++){
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		mer(x,y);
	}
	mer(n+1,n+1);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		if(x<y) swap(x,y);
		mer(n+abs(x),n+abs(y));
	}
	int hn=0,mn=0;

	for(int i=1;i<=n+m;i++){
		if(find(f[i])==find(1)) mn++;
		if(find(f[i])==find(n+1)) hn++;
	}
//	for(int i=1;i<=n+m;i++){
//		cout<<f[i]<<endl;
//	}
	cout<<min(mn,hn);
	return 0;
}
