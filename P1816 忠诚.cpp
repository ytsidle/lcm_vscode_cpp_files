#include <bits/stdc++.h>
using namespace std;
const int M=1e6+10;
int n,m,a[M],tree[M];
int lowbit(int x){
	return (-x)&x;
}
void update(int x,int v){
//	for(int i=u;i<=n;i+=lowbit(i)){
//		if(tree[i]>v){
//			tree[i]=v;
//		}else return;
//	}
	while(x<=n)
    {
        if(tree[x]>v)
          tree[x]=v;
         else
          return;     
        x+=lowbit(x);  
    }
}
int get_min(int x,int y){
    int now=y;
    int maxl=2147483647;
    while(now>=x)
    {
        if(now-lowbit(now)>x)
        {
           maxl=min(maxl,tree[now]);
           now-=lowbit(now);
        }
        else
         {
             maxl=min(maxl,a[now]);
             --now;
         }
    }
    return maxl;
}
int main(){
	memset(tree,0x3f,sizeof(tree));
//	scanf("%d%d",&m,&n);
//	for(int i=1;i<=m;i++){
//		scanf("%d",&a[i]);
//		update(i,a[i]);
//	}
//	for(int i=1;i<=n;i++){
//		int x,y;
//		scanf("%d%d",&x,&y);
//		printf("%d ",get_min(x,y));
//	}
    cin>>n>>m;
    int x,y;
    //n++;
    for(int i=1;i<=n;++i)
     {
         cin>>a[i];
         update(i,a[i]);
     }
    for(;m>0;--m)
    {
        cin>>x>>y;
        cout<<get_min(x,y)<<' ';
    }
	return 0;
}
