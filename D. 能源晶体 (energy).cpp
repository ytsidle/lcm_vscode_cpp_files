#include <bits/stdc++.h>
using namespace std;
const int P=998244353,N=5e3+5;
int n,k,f[N][N];
int main(){
	freopen("energy.in","r",stdin);
	freopen("energy.out","w",stdout);
	scanf("%d%d",&n,&k);
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(j>i) break;
			f[i][j]=(f[i-1][j-1]+f[i-j][j])%P;
		}
	}
	printf("%d",f[n][k]);
	return 0;
}
