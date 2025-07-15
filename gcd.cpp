#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+10;
int n,ans=1,prime[MAX],k;
bool vis[MAX];
inline int gcd(int x,int y){
	while(x!=0&&y!=0){
		x=x%y;
		swap(x,y);
	}
	if(x==0) return y;
	else return x;
}
void init(){
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			prime[++k]=i;
		}
		for(int j=1;prime[j]<=n/i;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}
int main(){
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	scanf("%d",&n);
	init();
//	n=100000;
	for(int i=2;i+2<=n;i++){
		if(vis[i]==0){
			if(n/i>1){
				ans=max(i,ans);
				continue;
			}
		}
		for(int j=i+2;j<=n;j++){
//				ans=max(ans,gcd(i,j));
			if(vis[j]) continue;
			int t=gcd(i,j);
			if(t>ans){
				ans=t;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
