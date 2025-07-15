#include <bits/stdc++.h>
using namespace std;

const int MAX=1e6+10;
int a[MAX],n,znum,onum,oth;
int main(){
//	freopen("arrange.in","r",stdin);
//	freopen("arrange.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0)znum++;
		else if(a[i]==1) onum++;
		else oth++;
	}
	if(znum<=(n+1)/2) printf("%d",0);
	else if((onum>1&&znum>1&&oth>1)||(znum==n)) printf("1");
	else printf("%d",2);
	return 0;
}
