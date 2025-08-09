#include <bits/stdc++.h>
using namespace std;
#define int long long
/*
思路:
1.枚举j
考虑j的情况
因为a[j]会=0,所以和只要算到j-1即可
那么i应该是对最小值尽可能没有影响的,
 输入时判断即可
 但是如果没有对最小值没影响的怎么办
 那么就说明每次最小值都在变小,选j-1,因为如果选大的就会使
 前面不一定会比现在小
*/
const int M=2e5+10;
int T,n,a[M],cf[M],ie[M],g[M],k[M];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		fill(ie,ie+1+n,0);
		ie[0]=0;
		k[0]=g[0]=LONG_LONG_MAX;
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]<g[i-1]){
				g[i]=a[i];
				cf[i]=cf[i-1]+g[i];
			} else{
				ie[i]=1;
				g[i]=g[i-1];
				cf[i]=cf[i-1]+g[i];
			}
			k[i]=min(k[i-1],g[i-1]-g[i]);//最小差
			ie[i]|=ie[i-1];//累计
//			cout<<"g:"<<g[i]<<" a: "<<a[i]<<" cf: "<<cf[i]<<" ie: "<<ie[i]<<"\n";
		}
		int ans=cf[n];
		for(int j=2;j<=n;j++){
			//枚举j
			if(ie[j-1]){
				//可以躺赢
				ans=min(ans,cf[j-1]);
			}else{
				//继承j-1
				ans=min(ans,cf[j-1]+min(k[j-1],a[j]));
			}
		}cout<<ans<<"\n";
	}
	return 0;
}
