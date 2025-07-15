#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int n,f[MAX];
long long i,j;
struct node{
	int e;
	long long i,j;
}no[MAX];
bool  cmp(node a,node b){
	return a.e>b.e;
}
long long find(long long x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
int main(){
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		memset(no,0x00,sizeof(no));
		for(int i=1;i<=n;i++){
			f[i]=i;
			scanf("%lld%lld%d",&no[i].i,&no[i].j,&no[i].e);
		}
		
		sort(no+1,no+1+n,cmp);
		bool flag=1;
		for(int i=1;i<=n;i++){
			if(no[i].e){
				long long fx=find(no[i].i),fy=find(no[i].j);
				f[fy]=fx;
				
			}else{
				long long fx=find(no[i].i),fy=find(no[i].j);
				if(fx==fy){
					flag=0;
					break;
				}
			}
		}if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
