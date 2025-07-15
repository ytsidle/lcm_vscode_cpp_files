#include <bits/stdc++.h>
using namespace std;
struct data{
	int data,father=0;
	int l=0,r=0;
}d[2200];
int a[1100],n,nodenum,mini1,mini2,ans;
void twomin(){
	mini1=0,mini2=0;
	int min1=2e9,min2=2e9;
	for(int i=1;i<=nodenum;i++){
		if(d[i].father==0){
			if(d[i].data<min1){
				min2=min1;
				min1=d[i].data;
				mini2=mini1;
				mini1=i;
			}else if(d[i].data<min2){
				min2=d[i].data;
				mini2=i;
			}
		}
	}
//	cout<<mini1<<" "<<mini2<<endl;
}
void dfs(int num,int dep){
	if(num==0) return;
	if(num<=n) {
		ans+=d[num].data*dep;
//		cout<<d[num].data<<" "<<dep<<endl;
	}
	dfs(d[num].l,dep+1);
	dfs(d[num].r,dep+1);
	
}
int main(){
	int m;
	scanf("%d",&m);
	while(m--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			d[i].data=a[i];
		}
		nodenum=n;
		while(nodenum<2*n-1){
			twomin();
			++nodenum;
//		cout<<mini1<<" "<<mini2<<endl;
//		cout<<d[mini1].data+d[mini2].data<<endl;
			d[nodenum].data=d[mini1].data+d[mini2].data;
			d[nodenum].l=mini1,d[nodenum].r=mini2;
			d[mini1].father=nodenum;
			d[mini2].father=nodenum;
		}
		dfs(nodenum,0);
		printf("%d\n",ans);	
	}

	return 0;
}
