#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int n,d,v[MAX],a[MAX];//dp[i][0]表示🚗开到第i个站时,花的最少钱数,dp[i][1]表示前面的站中油费最便宜的站
long long hlong(int f,int e){
	if(f==e){
		return 0;
	}else{
		long long ans=0;
		for(int i=f;i<e;i++){
			ans+=v[i];
		}return ans;
	}
}
int hol(long long len){
	if(len%d!=0){
		return len*1.0/d/1+1;
	}else return len/d;
}
int main(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<n;i++){
		scanf("%d",&v[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}

	printf("%d",hol(hlong(1,n))*a[1]);
//	cout<<hol(10);
	return 0;
}
