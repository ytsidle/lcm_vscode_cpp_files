#include <bits/stdc++.h>
using namespace std;
const int MAX=2e5+10;
int n,m,x,y,f[MAX],sons[MAX];
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
void merge(int a,int b){
	int fx=find(a),fy=find(b);
	if(fx!=fy){
		f[fy]=fx;
		sons[fx]+=sons[fy];
		sons[fy]=0;
	}
}
int main(){
//	freopen("sns.in","r",stdin);
//	freopen("sns.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		sons[find(x)]++;
		merge(x,y);
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		cout<<sons[i]<<" "<<i<<endl;
		sum+=(1ll*sons[i]*(sons[i]-1)/2);
	}
	printf("%lld",sum-m);
	
	return 0;
}
