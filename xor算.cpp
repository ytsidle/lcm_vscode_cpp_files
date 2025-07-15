#include <bits/stdc++.h>
using namespace std;
const int MA=1e9+7;
int ans,n,l,r,z;
void dfs(int c,int li,int su){
	if(c>n){
		ans+=(su==z);
		ans%=MA;
		return;
	}
	 
	if(c==n){
		int can=su^z;
		if(can==li){
			dfs(c+1,li-can,z);
			
		}return;
	}
	for(int i=0;i<=li;i++){
		int t=su^i;
		dfs(c+1,li-i,t);
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d%d",&n,&l,&r,&z);
	for(int i=l;i<=r;i++){
		dfs(1,i,0);
	}
	printf("%d",ans);
	return 0;
}
