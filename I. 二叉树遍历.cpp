#include <bits/stdc++.h>
using namespace std;
int h,p,n;
int tree[1024],t,k;
set<int> s;
void dfs(int num){
	if(p==1)printf("%d ",tree[num]);
	if(num*2<=n) dfs(num*2);
	if(p==2)printf("%d ",tree[num]);
	if(num*2+1<=n)  dfs(num*2+1);
	if(p==3)printf("%d ",tree[num]);
}
int main(){
	scanf("%d%d",&h,&p);
	n=pow(2,h)-1;
	while(1){
		
		scanf("%d",&t);
		if(s.find(t)==s.end()){
			tree[++k]=t;
			s.insert(t);
		}
		if(k==n) break;
	}
	dfs(1);
	return 0;
}
