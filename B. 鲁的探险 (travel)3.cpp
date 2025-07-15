#include <bits/stdc++.h>
using namespace std;
const int MAX=2e5+10;
int n,a[MAX],f[MAX],d[MAX],q[MAX],ans[MAX];
bool v[MAX];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&f[i]);
		d[f[i]]++;
	}
	int L=0,r=0;
   memset(v, 0, sizeof(v));
   for (int i = 1; i <= n; i++) // 初始化入度为0的点
      if (d[i] == 0)
      {
         q[r] = i;//q表示的是当前拓扑排序已经被删掉的点 
         r++;
      }
   	while (L < r)//拓扑排序 
   	{
        int x = q[L];
    	v[x] = 1;
    	d[f[x]]--;//x点被删除了，所以要把f[x]做处理(x,f[x]) 
    	if (d[f[x]] == 0)
    	{
        	q[r] = f[x];
        	r++;
    	}
    	L++;
   }
	for(int i=1;i<=n;i++){
		if(!v[i]){
			int x=i,st=x;
			int sum=a[x];
			v[x]=1;
			while(f[x]!=st){
				x=f[x];
				v[x]=1;
				sum+=a[x];
			}
			x=i,st=x;
			ans[x]=sum;
			while(f[x]!=st){
				x=f[x];
				ans[x]=sum;
			}
		}
	}
	for(int i=r-1;i>=0;i--){
		ans[q[i]]=ans[f[q[i]]]+a[q[i]];
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
