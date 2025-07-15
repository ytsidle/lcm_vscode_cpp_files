#include <bits/stdc++.h>
using namespace std;
const int MAX=5e4+10;
#define PII pair<int,int>
int n,dp[MAX],ma=1;
PII p[MAX];
bool cmp(PII a,PII b){
	return a.first<b.first;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i].first,&p[i].second);
	}
	sort(p+1,p+1+n,cmp);
	dp[1]=1;
	for(int i=2;i<=n;i++){
		int pn=0,type=0;
		for(int j=i-1;j>=1;j--){
			if(dp[j]>dp[pn]&&p[i].first>=p[j].second) pn=j,type=1;
		}if(type) dp[i]=dp[pn]+1;
		else dp[i]=1;
		ma=max(dp[i],ma);
	}printf("%d",ma);
	return 0;
}
