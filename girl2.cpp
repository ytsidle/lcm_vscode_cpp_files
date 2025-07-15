#include <bits/stdc++.h>
using namespace std;
int a[200],b[200],n,tmp[200],tmp2[200],max1,max2;
void work(){
	for(int i=1;i<=max(max1,max2);i++){
		tmp[i]=a[i],tmp2[i]=b[i];
	}
	int l=1,r1=max2,ans=0;

	while(1){
		while(l<=max1&&tmp[l]==0) l++;
		if(l>max1) break;
		while(tmp2[r1]==0) r1--;
		ans=max(ans,l+r1);
		int minv=min(tmp[l],tmp2[r1]);
		tmp[l]-=minv;
		tmp2[r1]-=minv;

	}
	printf("%d\n",ans);
}
int main(){
	freopen("girl.in","r",stdin);
	freopen("girl.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x]++;
		b[y]++;
		max1=max(max1,x);
		max2=max(max2,y);
		work();
	}
	return 0;
}
