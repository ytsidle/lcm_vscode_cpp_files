#include <bits/stdc++.h>
using namespace std;
const int M=1e6+10,P=1000000007;
char s[M]="";
int n;
long long ans=0,dp[10][M];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	if(s[1]!='?'){
		if(s[1]=='*') dp[1][1]=1;
		if(s[1]=='0') dp[2][1]=1;
		if(s[1]=='1'&&n!=1) dp[4][1]=1;
	}else{
		dp[1][1]=1;
		dp[2][1]=1;
		if(s[2]=='*'||s[2]=='?')dp[4][1]=1;
	}
//	dp[2][0]=dp[4][0]=1;
	for(int i=2;i<=n;i++){
		if(s[i]=='*'){
			dp[1][i]=dp[1][i-1]+dp[4][i-1]+dp[5][i-1];dp[1][i]%=P;
		}if(s[i]=='0'){
			dp[2][i]=dp[2][i-1]+dp[3][i-1];dp[2][i]%=P;
		}if(s[i]=='1'){//1l
			dp[3][i]=dp[1][i-1];
		}if(s[i]=='1'){//1r
//			cout<<"a:"<<(dp[2][i-1]+dp[3][i-1])<<endl;
			dp[4][i]=dp[2][i-1]+dp[3][i-1];dp[4][i]%=P;
		}if(s[i]=='2'){
			dp[5][i]=dp[1][i-1];
		}if(s[i]=='?'){
			for(int j=1;j<=1;j++){
				//枚举每种可能性
				if(1){
					dp[1][i]=dp[1][i-1]+dp[4][i-1]+dp[5][i-1];
					dp[1][i]%=P;
				}if(1){
					dp[2][i]=dp[2][i-1]+dp[3][i-1];dp[2][i]%=P;
				}if(1){//1L
					dp[3][i]=dp[1][i-1];
				}if(1){//1R
					dp[4][i]=dp[2][i-1]+dp[3][i-1];dp[4][i]%=P;
				}if(1){//2
					dp[5][i]=dp[1][i-1];				
				}
			}
		}
	}
//	for(int i=1;i<=5;i++){
//		for(int j=0;j<=n;j++) cout<<dp[i][j]<<" ";
//		cout<<endl;
//	}
//	for(int i=1;i<=5;i++){
//		ans+=dp[i][n];
//		ans%=P;
//	} 
	cout<<((dp[1][n]+dp[2][n]+dp[3][n]))%P;
	return 0;
}
