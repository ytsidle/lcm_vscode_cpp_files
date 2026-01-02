#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int n,m,a[N],can[N],scccnt,low[N],dfn[N],ti,ins[N],b[N],ma[N],mi[N],deg[N],ans;
vector<int> g[N],st,g2[N],g3[N];                                                                                                                                                                                                                                                                                                                                                                        ;
void add(int u,int v) {
    g[u].emplace_back(v);
}
void tarjan(int x){
    low[x]=dfn[x]=++ti;
    st.emplace_back(x);
    ins[x]=1;
    for(auto v:g[x]){
        if(!dfn[v]){
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }else if(ins[v]){
            low[x]=min(low[x],dfn[v]);
        }
    }
    if(low[x]==dfn[x]){
        ++scccnt;
        int y;
        do{
            y=st.back();
            ins[y]=0;
            b[y]=scccnt;
            st.pop_back();
            ma[scccnt]=max(ma[scccnt],a[y]);
            mi[scccnt]=min(mi[scccnt],a[y]);
        }while(x!=y);
    }
}
struct Dat{
    int c,mao,mio;
};
void dfs3(int x){
    can[x]=1;
    for(auto v:g3[x]){
        if(!can[v]) dfs3(v);
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    memset(mi,0x3f,sizeof(mi));
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        if(z==1)add(x,y);
        else{
            add(x,y);
            add(y,x);
        }
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    for(int i=1;i<=n;i++){
        for(auto v:g[i]){
            if(b[i]!=b[v]){
                g2[b[i]].emplace_back(b[v]);
                g3[b[v]].emplace_back(b[i]);
                deg[b[v]]++;
            }
        }
    }dfs3(b[n]);
    queue<Dat> q;
    q.push({b[1],ma[b[1]],mi[b[1]]});
    while(!q.empty()){
        int x=q.front().c,mao=q.front().mao,mio=q.front().mio;
        if(can[x])ans=max(ma[x]-mio,ans);
        q.pop();
        for(auto v:g2[x]){
            if(--deg[v]==0){
                q.push({v,max(mao,ma[v]),min(mio,mi[v])});
            }
        }
    }
    cout<<max(0ll,ans);
    return 0;
} 