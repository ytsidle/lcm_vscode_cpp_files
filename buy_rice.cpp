#include <bits/stdc++.h>
using namespace std;
const int MAX=1000090;
int dp[MAX],n,s,p,num,k=1,cnt=1,ln[30],lv[30],tp;//dp[i][j]表示买第i项中在j元下最多的斤数
int main(){
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>num>>p;
		cnt=0;
		tp=num;
		k=1;
		while(k<tp){
			cnt++;
			ln[cnt]=k;
			lv[cnt]=k*p;
			tp=tp-k;
//			cout<<"tp:"<<tp<<endl;
			k*=2;
			
		}if(tp){
			cnt++;
			ln[cnt]=tp;
			lv[cnt]=tp*p;
		}
//		for(int i=1;i<=cnt;i++)  cout<<ln[i]<<" "<<lv[i]<<endl;
		//0,1背包
		for(int i=1;i<=cnt;i++){
			for(int j=s;j>=lv[i];j--){
				dp[j]=max(dp[j],ln[i]+dp[j-lv[i]]);
			}
		}
	
	}
	cout<<dp[s];
	return 0;
}
