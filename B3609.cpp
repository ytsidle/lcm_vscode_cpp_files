#include <bits/stdc++.h>
using namespace std;
vector<int> g[10010];
int n,m,dfn[10010],low[10010],ou[10010],ti,ins[10010],scnt,scf[10010];
vector<int> scc[10010],st;
void dfs(int x){
    dfn[x]=low[x]=++ti;
    ins[x]=1;
    st.emplace_back(x);
    for(int v:g[x]){
        if(!dfn[v]){
            //树边
            dfs(v);
            low[x]=min(low[x],low[v]);
        }else if(ins[v]){
            //如果在栈上
            low[x]=min(low[x],dfn[v]);
        }
    }
    if(low[x]==dfn[x]){
        scnt++;
        while(st.size()&&(st.back())!=x){
            scf[st.back()]=x;
            scc[x].emplace_back(st.back());
            ins[st.back()]=0;
            st.pop_back();
        }ins[st.back()]=0;
        scf[x]=x;
        scc[x].emplace_back(x);
        st.pop_back();
        
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
        ti=0;
        if(!dfn[i]) dfs(i);
    }
    cout<<scnt<<"\n";
    for(int i=1;i<=n;i++){
        if(scc[scf[i]].size()&&ou[scf[i]]==0){
            ou[scf[i]]=1;
            sort(scc[scf[i]].begin(),scc[scf[i]].end());
            for(auto t:scc[scf[i]]) cout<<t<<" ";
            cout<<"\n";
        }
    }
    return 0;
}