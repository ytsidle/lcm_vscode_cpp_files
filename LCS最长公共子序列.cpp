#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int a[MAX],b[MAX],c[MAX],n,dp[MAX],k;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		c[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		b[i]=c[b[i]];
	}
	dp[++k]=b[1];
	for(int i=2;i<=n;i++){
		if(b[i]>dp[k]) dp[++k]=b[i];
		else{
			int l=1,r=k;
			while(l<=r){
				int mid=(l+r)/2;
				if(dp[mid]>=b[i]) r=mid-1;
				else l=mid+1;
			}
			dp[l]=b[i];
		}
	}
	printf("%d",k);
	return 0;
}