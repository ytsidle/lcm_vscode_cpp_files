#include <iostream>
#include <cstdio>
using namespace std;
//暴力
//加速从头文件加速起
//递归
int n,a[9],k;
bool f[9];//默认为false,意为没使用
bool check(){
	for(int i=1;i<n;i++){
		if(!(a[i]+a[i+1]<k)) return false;
	}
	return true;
}
void out(){
	for(int i=1;i<=n;i++){
		printf("%d",a[i]);
	}printf("\n");
}
void dfs(int c){
	
	for(int i=1;i<=n;i++){
		if(f[i]==false){
			f[i]=true;
			a[c]=i;
			if(c==n && check()) out();
			else dfs(c+1);
			f[i]=false;
		}
	}
	

}

int main(){
	scanf("%d%d",&n,&k);
	dfs(1);
	return 0;
}
