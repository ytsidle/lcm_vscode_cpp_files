#include <bits/stdc++.h>
using namespace std;
int n,q;
int main(){
	scanf("%d%d",&n,&q);
	map<int,map<int,int> > a;
	for(int i=1;i<=q;i++){
		int as,b,c,d;
		scanf("%d%d%d",&as,&b,&c);
		if(as==1){
			scanf("%d",&d);
			a[b][c]=d;
		}else{
			printf("%d\n",a[b][c]);
		}
	}
	return 0;
}
