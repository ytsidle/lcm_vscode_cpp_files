#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,dfn[N],low[N],ti,ins[N],scnt;
vector<pair<int,int> > g[N];
vector<int> stk,ans[N];
void tarjan(int u,int id){
    dfn[u]=low[u]=++ti;
    ins[u]=1;
    stk.emplace_back(u);
    for(auto [id2,v]:g[u]){
        if(id2==id) continue;
        if(!dfn[v]){
            tarjan(v,id2);
            low[u]=min(low[u],low[v]);
        }else if(ins[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u]){
        scnt++;
        int y;
        do{
            y=stk.back();
            ins[y]=0;
            stk.pop_back();
            ans[scnt].emplace_back(y);

        }while(y!=u);
        
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].emplace_back(i,v);
        g[v].emplace_back(i,u);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i,-1);
        }
    }
    cout<<scnt<<"\n";
    for(int i=1;i<=scnt;i++){
        cout<<ans[i].size()<<" ";
        for(auto x:ans[i]){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    return 0;
}