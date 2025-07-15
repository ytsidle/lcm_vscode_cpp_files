#include <bits/stdc++.h>
using namespace std;
const int MAX=2e5+10;
int f[MAX];
int v,t,n;
int main(){
	cin>>v;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		for(int j=v;j>=t;j--){
			f[j]=max(f[j],f[j-t]+t);
		}
	}cout<<v-f[v];
	return 0;
}
