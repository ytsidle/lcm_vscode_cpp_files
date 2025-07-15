#include <bits/stdc++.h>
using namespace std;
//基础的dfs
int a[100010],tree[100010][3],fa[100010],n,root;
long long ans,cnt;
void dfs(int num){
	if(num==0) return ;
	
	dfs(tree[num][2]);
	cnt++;
	ans+=a[num];
	if(cnt==(n/2)){
		cout<<ans;
		exit(0);
	}dfs(tree[num][1]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//dfs
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int x,y;cin>>x>>y;
		fa[x]=fa[y]=i;
		tree[i][1]=x;
		tree[i][2]=y;
	}
	for(int i=1;i<=n;i++){
		if(fa[i]==0) {
			root=i;
			break;
		}
	}
	dfs(root);
	return 0;
}
