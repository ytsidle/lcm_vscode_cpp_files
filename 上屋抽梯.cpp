#include <bits/stdc++.h>
using namespace std;
const int MAXN = 6060;
int dis[MAXN],p[MAXN][MAXN];
int n;
vector<int> a[MAXN];
void dfs(int now,int fa){
	int sum=0;
	for(int i=0;i<a[now].size();i++){
		if(a[now][i]==fa) continue;
		dis[a[now][i]]=p[now][a[now][i]];
		dfs(a[now][i],now);
		sum+=dis[a[now][i]];
	}
	if(sum)dis[now]=min(sum,dis[now]);
}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin >> n; // 读取节点数量

    int u, v, w;
    for (int i = 1; i < n ; ++i) { // 读取n-1条边
        cin >> u >> v >> w;
        a[u].push_back(v); // 将v节点加入u节点的邻接表中
        a[v].push_back(u); // 将u节点加入v节点的邻接表中
    	p[u][v]=p[v][u]=w;
	}

    // 此处可以添加后续代码，例如遍历邻接表等
	
	dis[1]=114514520;
	dfs(1,0);
	cout<<dis[1];
    return 0;
}
