#include <bits/stdc++.h>
using namespace std;
//想法:
/*
	DP动归
	dp[i]表示在i个清单下,最多的数量
	若能连;dp[i]=dp[i-1]+node[i].v2-node[i].v1+1
	否则 max(dp[i-1],0); node[i].v1=node[i-1].v1 
	node[i].v2=node[i-1].v2
	例:
	1 3   dp 3

	1 3	 	 3
	
	7 8 	5
*/
struct node{
	int v1,v2;
};
node p[1010];
bool cmp(node a,node b){
	return a.v1<b.v1;
}
int n,dp[1010];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i].v1,&p[i].v2);
	}
	sort(p+1,p+1+n,cmp);
//	for(int i=1;i<=n;i++){
//		cout<<p[i].v1<<" "<<p[i].v2<<endl;
//	}
	for(int i=1;i<=n;i++){
		if(p[i-1].v2<p[i].v1) dp[i]=dp[i-1]+(p[i].v2-p[i].v1)+1;
		else{
			dp[i]=max(dp[i-1],0); 
			p[i].v1=p[i-1].v1;
			p[i].v2=p[i-1].v2;
		}
	}

	cout<<dp[n];
	return 0;
}
