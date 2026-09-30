#include<bits/stdc++.h>
using namespace std;
#define MAXN 2005
// 0. 整体变量
int n,m;
int ans=0,tot=0;
vector<int> V[MAXN],G[MAXN]; 
// 1. 边双连通分量
int dfn[MAXN],low[MAXN],sum,cnt=0;
int in[MAXN];
stack<int> s;
void dfs(int x,int fa){
	dfn[x]=low[x]=++sum;
	s.push(x);
	for(auto i:V[x]){
		if(!dfn[i]){
			dfs(i,x);
			low[x]=min(low[x],low[i]);
		}else if(fa!=i&&dfn[i]<dfn[x]) low[x]=min(low[x],dfn[i]);
	}
	if(low[x]==dfn[x]){
		cnt++;
		in[x]=cnt;
		int v=s.top();
		s.pop();
		while(v!=x){
            in[v]=cnt;
			v=s.top();
            tot++;
			s.pop();
		}
	}
}
// 2. 重构树
void rebuild(){
    for(int i=1,t;i<=n;i++){
        t=in[i];
        for(auto v:V[i]){//和每一个对应的点连边（有重边没关系）
            if(t==in[v]) continue;
            G[t].push_back(in[v]);
            G[in[v]].push_back(t);
        }
    }
    n=cnt;
}
// 3. 树的直径
int L,tmp;
bool vis[100005],vis2[100005];
void dfs2(int now,int step){
	if(step>L) L=step,tmp=now;
	vis[now]=vis2[now]=1;//vis2表示这个点所在的树是否访问过
	for(auto i:G[now]){
		if(!vis[i]) dfs2(i,step+1);
	}
	return ;
}
int get_diameter(int root){
    memset(vis,0,sizeof(vis));
    L=-1;
	dfs2(root,1);//注意是1
	memset(vis,0,sizeof(vis));
	dfs2(tmp,1);
    return L;
}
// 4. 计算度为 1 的节点数和总结点数
int find_D1(int root,int fa){
    int ans=0,cnt=0;
    vis[root]=1;
    for(auto i:G[root]){
        if(!vis[i]) ans+=find_D1(i,root),cnt++;
    }
    return ans+(cnt==(fa==-1));
}
int find_ALL(int root){
    int ans=1;
    vis[root]=1;
    for(auto i:G[root]){
        if(!vis[i]) ans+=find_ALL(i);
    }
    return ans;
}
// 5. 计算
int main(){
    // 5.1. 输入
    cin>>n>>m;
    int x,y;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        V[x].push_back(y);
        V[y].push_back(x);
    }
    // 5.2. 合并边双联通分量，重构树
    for(int i=1;i<=n;i++){
        if(!dfn[i]) dfs(i,-1);
    }
    rebuild();
    // 5.3. 对于每一棵树
    for(int Rt=1;Rt<=n;Rt++){
        if(!vis2[Rt]){
            // 5.3.1. 计算直径和度为 1 的节点数和N
            int _L=get_diameter(Rt);
            memset(vis,0,sizeof(vis));
            int _D1=find_D1(Rt,-1);
            memset(vis,0,sizeof(vis));
            int _N=find_ALL(Rt);
            // 5.3.2. 一棵树的ans：`N-(直径长度+度为1的节点数-2)`
            tot++;
            cout<<Rt<<" "<<_N<<" "<<_D1<<" "<<_L<<'\n';
            if(_N==1) continue;//注意特判
			ans+=_N-(_L+_D1-2);
        }
    }
    cout<<tot<<" tt\n";
    // 5.4. 森林：`每一棵树的ans+树的数量-1`
    cout<<ans+tot-1<<endl;
    return 0;
}
