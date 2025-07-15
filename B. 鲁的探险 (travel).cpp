#include <bits/stdc++.h>
using namespace std;
const int MAX=2e5+10;
int n,a[MAX],f[MAX],st[MAX],d[MAX],fa[MAX];//st为0代表没走,st为1代表走了且没环,2为有环
bool dfs(int grand,int num,int sum){
	
	if(f[num]==grand){
		st[num]=a[num];
		d[num]=sum+a[num];
		return 1;
	}if(f[num]==num){
		st[num]=a[num];
		d[num]=a[num];
		return 0;
	}
	bool re=dfs(grand,f[num],sum+a[num]);
	if(num!=grand){
		st[num]=st[f[num]]+a[num];
		if(re){
			d[num]=d[f[num]];
		}else{
			d[num]=d[f[num]]+a[num];
		}
		return re;
	}
	else{
		d[num]=st[f[num]]+a[num];
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&f[i]);
		if(i!=f[i])fa[f[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(!d[i])dfs(i,i,0);
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",d[i]);
	}
	return 0;
}
