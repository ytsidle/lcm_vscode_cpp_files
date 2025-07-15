#include <bits/stdc++.h>
using namespace std;

int w,h,c,pos,num,mins;
long long dp[1010*1010][3],a[1010][1010];
long long mon(int pos1,int pos2){
	
	return a[(pos1-1)/h][(pos1-1)%h]+a[(pos2-1)/h][(pos2-1)%h]+c*(abs(((pos1-1)/h)-((pos2-1)/h))+abs(((pos1-1)%h)-((pos2-1)%h)));
}
int main(){
	scanf("%d%d%d",&w,&h,&c);
	for(int i=0;i<w;i++){
		for(int j=0;j<h;j++){
			scanf("%lld",&a[i][j]);
			pos=i*h+j+1;
//			if(dp[pos-1][1]==0){
//				dp[pos][1]=pos;
//				dp[pos][0]=a[i][j];
//			}else if(dp[pos-1][2]==0){
//				dp[pos][1]=dp[pos-1][1];
//				dp[pos][2]=pos;
//				dp[pos][0]=dp[pos-1][0]+a[i][j];
//			}else{
//				//假设2更大
//				if(a[i][j]<dp[dp[pos-1][2]][0]){
//					dp[pos][2]=pos;
//					dp[pos][1]=dp[pos-1][1];
//					dp[pos][0]=dp[dp[pos][1]][0]+a[i][j];
//					check(dp[pos][1],dp[pos][2]);//检查大小
//				}
//			}
			if(pos==1){
				dp[1][0]=a[i][j];
			}else if(pos==2){
				dp[2][0]=a[i][j];
				dp[2][0]=mon(1,2);
				dp[2][1]=1;
				dp[2][2]=2;
			}else{
				dp[pos][0]=a[i][j];
				long long at=mon(dp[pos-1][1],pos);
				long long bt=mon(dp[pos-1][2],pos);
				mins=min(dp[pos-1][0],min(at,bt));
				dp[pos][0]=mins;
				if(mins==dp[pos-1][0]){
					dp[pos][1]=dp[pos-1][1];
					dp[pos][2]=dp[pos-1][2];
				}else if(mins==at){
					dp[pos][1]=dp[pos-1][1];
					dp[pos][2]=pos;
				}else{
					dp[pos][1]=dp[pos-1][2];
					dp[pos][2]=pos;
				}
			}
	
			
		}
	}
//	cout<<mon(2,3)<<endl;
//	for(int i=1;i<=w*h;i++){
//		printf("%lld ",dp[i][0]);
//	}cout<<endl;
//	for(int i=1;i<=w*h;i++){
//		printf("%lld ",dp[i][1]);
//	}cout<<endl;
//	for(int i=1;i<=w*h;i++){
//		printf("%lld ",dp[i][2]);
//	}cout<<endl;
	printf("%lld",dp[w*h][0]);
	return 0;
}                         
