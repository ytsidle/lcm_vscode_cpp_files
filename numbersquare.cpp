#include <bits/stdc++.h>
using namespace std;
int n,a=0,b=0,c=0;
int main(){
	scanf("%d",&n);
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int x=0;x<=n;x++){
				if((i+j)%2==0 && (j+x)%3==0 && (i+j+x)%5 ==0){
					if((i+j+x)>=(a+b+c)){
						a=i,b=j,c=x;
					}
				}
			}
		}
	}cout<<a+b+c;
	return 0;
}
