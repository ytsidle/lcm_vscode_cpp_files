#include <bits/stdc++.h>
using namespace std;
int t,n,e,a,b,k,f[510];
struct edge{
	int a,b,k;
}es[250010];
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
void mer(int x,int y,int *cnt){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		f[fy]=fx;
		cnt++;
	}
}
bool cmp(edge a,edge b){
	return a.k<b.k;
}
int main(){
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d%d",&n,&e);
		int cnt=0,ans=0,m=0;
		
		for(int j=0;j<n;j++){
			f[i]=i;
		}
		for(int j=0;j<e;j++){
			scanf("%d%d%d",&a,&b,&k);
			if(k==0){
				mer(a,b,&cnt);
			}
			m++;
			es[m].a=a,es[m].b=b,es[m].k=k;
		}
		cout<<cnt<<endl;
		sort(es+1,es+1+m,cmp);
		for(int j=1;j<=m;j++){
//			cout<<es[j].k<<endl;
			int fx=find(es[j].a),fy=find(es[j].b);
			if(fx!=fy){
				cnt++;
				f[fy]=fx;
				ans+=es[j].k;
			}
			if(cnt==n-1){
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}