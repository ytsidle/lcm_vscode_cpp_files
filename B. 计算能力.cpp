#include <bits/stdc++.h>
using namespace std;
//树状数组

const int M=1e5+10;
int n,tree[M],a[M],m;
int lowbit(int x){
	return -x&x;
}
void add(int p,int x){
	for(int i=p;i<=n;i+=lowbit(i)) tree[i]+=x;
}
int query(int x){
	int sum=0;
	for(int i=x;i>=1;i-=lowbit(i)) sum+=tree[i];
	return sum;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		add(i,a[i]);
	}
	int x,y;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		printf("%d\n",query(y)-query(x-1));
	}
	return 0;
}
