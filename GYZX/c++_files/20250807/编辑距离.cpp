#include <bits/stdc++.h>
using namespace std;
// 编辑距离
int dp[2050][2050];
string s,s2;
int main(){
	cin>>s>>s2;
	s=" "+s;
	s2=" "+s2;
	
//	if(s.size()>s2.size()) {
//		string tmp=s;
//		s=s2;
//		s2=tmp;
//	}cout<<s<<" "<<s2<<"\n";
	int n=s.size()-1;
	int m=s2.size()-1;
	for(int i=1;i<=n;i++) dp[i][0]=i;
	for(int i=1;i<=m;i++) dp[0][i]=i;
	//dp定义 dp[i][j]表示s[1..i]和s2[1..i]的编辑距离
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i]==s2[j]){
				//不用编辑
				dp[i][j]=dp[i-1][j-1];
			}else{
				dp[i][j]=min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1});
			}
		}
	}
	cout<<dp[n][m];
	return 0;
}