// Problem: P9493 「SFCOI-3」进行一个列的排
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P9493
// Memory Limit: 32 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10,mod=998244353;
int dp[N][2],n,l[N];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++) cin>>l[i];
        int flag=1;
        for(int i=0;i<n;i++){
            if(l[i]<i) flag=0;
        }
        if(flag==0){
            cout<<"0\n";
            continue;
        }
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			if(i-1>=l[0]||(n-i)>=l[0]) dp[i][0]=1;
			else dp[i][0]=0;
		}
        int p=1;
		for(int i=1;i<n;i++,p^=1){
            for(int j=1;j<=n;j++) dp[j][p]=0;
			for(int j=1;j<=n;j++){
				if(j+i-1-l[i]>=0)dp[j][p]=(dp[j][p^1]+dp[j][p])%mod;
				if(j+l[i]<=n)  dp[j][p]=(dp[j][p]+dp[j+1][p^1])%mod;
			}
		}
		cout<<dp[1][p^1]<<"\n";
	}
	
	return 0;
}