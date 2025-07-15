#include <bits/stdc++.h>
using namespace std;
int m,n,sum,temp,can;
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&temp);
		if(sum+temp<=m){
			can+=1;
			sum+=temp;
		}
	}printf("%d",(n-can));
	return 0;
}
