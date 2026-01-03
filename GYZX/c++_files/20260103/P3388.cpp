#include <bits/stdc++.h>
using namespace std;
int n,m,rt,dfn[20010],low[20010],ti,ins[20010],pn,cut[20010];
vector<int> g[20010],st,pl;
void tarjan(int u){
    dfn[u]=low[u]=++ti;
    st.push_back(u);
    int ch=0;
    for(auto v:g[u]){
        if(!dfn[v]){
            ch++;
            tarjan(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                if(u!=rt||ch>=2){
                    if(cut[u]==0){
                        pn++;
                        pl.emplace_back(u);
                        cut[u]=1;
                    }
                    
                }
                int y=st.back();
                while(u!=y){
                    ins[y]=0;
                    st.pop_back();
                    y=st.back();
                }
            }
        }else{
            low[u]=min(low[u],dfn[v]);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            rt=i;
            tarjan(i);
        }
    }
    cout<<pn<<"\n";
    sort(pl.begin(),pl.end());
    for(int i:pl) cout<<i<<" ";
    return 0;
}