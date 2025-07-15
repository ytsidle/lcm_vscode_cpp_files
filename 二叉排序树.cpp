#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
struct data{
	int num,fa,l,r;
}node[MAX];
int n,a[MAX],k=1;
void insert(int id){

	bool flag=0;
	for(int i=1;i<=k;i++){
		if(node[i].num==a[id]){
			flag=1;
			break;
		}
	}
	if(!flag){
		node[++k].num=a[id];
		int p=1;
		while(1){
			if(node[p].num>a[id]&&node[p].l!=0){
				p=node[p].l;
			}else if(node[p].num<a[id]&&node[p].r!=0){
				p=node[p].r;
			}else break;
			//		printf("1\n");
		}
		if(node[p].num>a[id]){
			node[p].l=k;
			node[k].fa=p;
		}else{
			node[p].r=k;
			node[k].fa=p;
		}
	}
}
void dfs(int num,int type){
	if(num==0) return;
	dfs(node[num].l,type);
	if(type==1) printf("%d ",node[num].num);
	dfs(node[num].r,type);
	if(type==2) printf("%d ",node[num].num);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	node[1].num=a[1];
	for(int i=2;i<=n;i++) insert(i);
	dfs(1,1);
	printf("\n");
	dfs(1,2);

	return 0;
}
