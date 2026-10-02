#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
int n,m,w[N],dfn[N],ti,low[N],ins[N],scccnt,sum[N],whi[N],dp[N];
vector<int> g[N],st,g2[N];
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
            whi[y]=scccnt;
            st.pop_back();
            sum[scccnt]+=w[y];
        }while(x!=y);
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].emplace_back(v);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            ti=0;
            tarjan(i);
        }
    }
    for(int i=1;i<=n;i++){
        for(auto v:g[i]){
            if(whi[i]!=whi[v]){
                g2[whi[i]].emplace_back(whi[v]);
            }
        }
    }
    int ans=0;
    for(int i=scccnt;i;i--){
        dp[i]=max(dp[i],sum[i]);
        for(int v:g2[i]){
            dp[v]=max(dp[v],dp[i]+sum[v]);
        }
    }
    for(int i=1;i<=scccnt;i++) ans=max(ans,dp[i]);
    cout<<ans;
    return 0;
}