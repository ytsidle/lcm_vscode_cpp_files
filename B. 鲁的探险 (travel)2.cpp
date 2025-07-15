#include <bits/stdc++.h>
using namespace std;
const int MAX=2e5+10;
int n,a[MAX],f[MAX];//st为0代表没走,st为1代表走了且没环,2为有环
bool go[MAX];
int dfs(int num){
//	
	go[num]=1;
	if(go[f[num]]==1){
//		cout<<num<<" "<<f[num]<<endl;
		return a[num];
	}
	return a[num]+dfs(f[num]);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&f[i]);
	}
	for(int i=1;i<=n;i++){
		memset(go,0,sizeof(go));
		printf("%d\n",dfs(i));
	}

	return 0;
}
