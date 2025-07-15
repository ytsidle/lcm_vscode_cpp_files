#include <bits/stdc++.h>
using namespace std;
//树的直径
//链式前向星
struct Edge {
    int to,p, next; 
}edge[100005];
int n, pre[50005], cnt = 0 , depth[50005];
void add(int u, int v, int w) {
    edge[++cnt]={v,w,pre[u]};
    pre[u]=cnt;
}
int mp=0;
void dfs(int u, int f) {
    for(int i = pre[u]; i; i = edge[i].next) {
        int v = edge[i].to;
        if(v == f) continue;
        depth[v] = depth[u] + edge[i].p;
        if(depth[v] > mp) {
           mp = depth[v];
        }
        dfs(v, u);
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w); 
        add(v, u, w);
    }
    depth[0]=INT_MIN;
    dfs(1,0);
    int s = mp,ans=mp;
    for(int i=1;i<=n;i++){
        if(depth[i]==s){
            mp=0;
            dfs(i,0);
            ans=max(mp,ans);
            // return 0;
        }
    }
    cout<<ans;
    return 0;
}