#include <bits/stdc++.h>
using namespace std;
const int M=1e5+10;
int dui[8]={0,0,1,7,4,2,6,8},T;
int cnt[10]={6,2,5,5,4,5,6,3,7,6};
int nums[M],mp,n,sum;
void mplus(int num){
	mp=max(1,mp);
	nums[1]+=num;
	int p=1;
	while(nums[p]>=10){
		nums[p+1]+=(nums[p]/10);
		nums[p]%=10;
		mp=max(mp,p+1);
		p++;
	}
}
void solve(){
	mplus(7);
	while(1){
		mplus(1);
		sum=0;
//		for(int i=mp;i>=1;i--){
//			printf("%d",nums[i]);
//		}
//		printf("\n");
		for(int i=1;i<=mp;i++){
//			cout<<nums[i]
			sum+=cnt[nums[i]];
		}
		if(sum==n){
			for(int i=mp;i>=1;i--){
				printf("%d",nums[i]);
			}
			printf("\n");
			break;
		}
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n==1){
			printf("-1\n");
			continue;
		}
		if(n<=7){
			printf("%d\n",dui[n]);
			continue;
		}
		if(n%7==0){
			for(int i=1;i<=n/7;i++){
				printf("8");
			}
			printf("\n");
			continue;
		}
		if(n%7==1){
			printf("10");
			for(int i=1;i<=(n-8)/7;i++){
				printf("8");
			}
			printf("\n");
			continue;
		}
		solve();
	}
	return 0;
}
