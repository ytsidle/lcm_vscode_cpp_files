#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
struct Node{
	int color,f;
	vector<int> son;
}nodes[MAX];
int n,ans,p,to[MAX];
void dfs(int num){
//	cout<<num<<endl;
	nodes[num].color=nodes[nodes[num].f].color;
	
	if(nodes[num].color!=to[num]){
		ans++;
		nodes[num].color=to[num];
		
	}
	for(auto k:nodes[num].son){
		dfs(k);
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		scanf("%d",&p);
		nodes[i].f=p;
		nodes[p].son.push_back(i);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&to[i]);
	}
	dfs(1);

	printf("%d",ans);
	return 0;
}
