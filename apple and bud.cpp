#include <bits/stdc++.h>
using namespace std;
int n,x,y,num;

int main(){
	scanf("%d%d%d",&n,&x,&y);
	if(!(n<y/x)){
	
		if(y%x==0){
			num=y/x;
		}else{
			num=y/x;
			num++;
		}
	}else{
		printf("%d",0);
		return 0;
	}
	printf("%d",n-num);
	return 0;
}
