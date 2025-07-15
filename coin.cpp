#include <bits/stdc++.h>
using namespace std;
bool is[5010]={};//is[i]表示第i个硬币是否正面

int n,m;
int main(){
	memset(is,1,sizeof(is));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(j>=i&&j%i==0){
//				cout<<j<<endl;
				is[j]=!is[j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		
		if(is[i]==1){
			cout<<i<<" ";
		}
//		cout<<is[i]<<" ";
	}
	return 0;
}
