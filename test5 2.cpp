#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+1000;
unsigned int a[MAX],b[MAX],n,num=1;
struct node{
	unsigned int val1,val2;
};
node dp[MAX];
int main(){
	scanf("%u",&n);
	for(unsigned int i=1;i<=n;i++){
		scanf("%u",&b[i]);
		
	}
	sort(b+1,b+1+n);
	int num1=0;
	for(unsigned int i=1;i<=n;i++){
		if(i==b[num]) num++;
		else{
			int nu=i-dp[num].val2;
			bool type=true;
			for(int j=1;j<=num1;j++){
				if(dp[j].val2==nu){
					type=false;
					break;
				}
			}for(int j=1;j<=num;j++){
				if(b[j]==i){
					type=false;
					break;
				}
			}if(type){
				cout<<i<<endl;
				exit(0);
			}else{
				num1++;
				dp[num].val1=i;
				dp[num].val2=i;
			}
		}
	}
	return 0;
}
