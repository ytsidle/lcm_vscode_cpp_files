#include <bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n%7==0){
			for(int i=1;i<=n/7;i++){
				printf("8");
			}printf("\n");
		}else if(n%6==0){
			printf("6");
			for(int i=1;i<n/6;i++){
				printf("0");
			}printf("\n");			
		}else if(n%5==0){
			for(int i=1;i<=n/5;i++){
				printf("5");
			}printf("\n");			
		}else if(n%4==0){
			for(int i=1;i<=n/5;i++){
				printf("4");
			}printf("\n");			
		}else if(n%6==3){
			printf("45");
			for(int i=1;i<=n/6-1;i++){
				printf("0");
			}printf("\n");
		}else if(n%4==2){
			printf("6");
			for(int i=1;i<=n/4-1;i++){
				printf("4");
			}printf("\n");			
		}
		else printf("-1\n");
	}
	return 0;
}
