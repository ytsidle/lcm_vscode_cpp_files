#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int t,n,k,len;
int a[MAX][3];

int main(){
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d%d",&n,&k);
		
		for(int j=1;j<=n;j++){
			scanf("%d%d",&a[j][1],&a[j][2]);
			for(int x=a[j][1];x<=a[j][2];x++) f[x]++;
			len=max(len,a[j][2]);
		}
		
	}
	return 0;
}
