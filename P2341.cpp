#include <bits/stdc++.h>
using namespace std;
int n,m,dfn[10010],gcnt=0,low[10010],ti,ins[10010],de[10010],sum[10010],scnt,be[10010],deg[10010];
vector<int> g[10010],g2[10010],st;
bool vis[10010];
void dfs(int x){
    low[x]=dfn[x]=++ti;
    ins[x]=1;
    st.emplace_back(x);
    for(int v:g[x]){
        if(!dfn[v]){
            dfs(v);
            low[x]=min(low[x],low[v]);
        }else if(ins[v]){
            low[x]=min(low[x],dfn[v]);
        }
    }
    if(dfn[x]==low[x]){
        int y;
        scnt++;
        do{
            y=st.back();
            sum[scnt]++;
            ins[y]=0;
            be[y]=scnt;
            st.pop_back();
        }while(x!=y);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].emplace_back(v);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])
        {ti=0;dfs(i);}
    }
    
    for(int i=1;i<=n;i++){
        for(auto v:g[i]){
            if(be[i]!=be[v]){
                deg[be[i]]++;
                g2[be[v]].emplace_back(be[i]);
            }
        }
    }
    int ans=0,fl=0;
    for(int i=1;i<=scnt;i++){
        if(deg[i]==0){
            ans+=sum[i];
            fl++;
        } 
    }
    if(fl>1) ans=0;
    cout<<ans;
    return 0;
}