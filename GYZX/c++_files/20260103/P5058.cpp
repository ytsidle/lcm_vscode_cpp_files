#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+10;
int low[N],dfn[N],is[N],ins[N],ti,n,m,sa,sb,u[3*N],v[3*N],vis[N],ans=INT_MAX,d[N],f[N],e[N],INF,cnt;
vector<pair<int,int>> g[N];
vector<int> st;
vector<int> re;
void tarjan(int x,int id){

    dfn[x]=low[x]=++ti;
    st.push_back(x);
    ins[x]=1;
    for(auto [v,id2]:g[x]){
        if(id2==id) continue;
        if(!dfn[v]){
            tarjan(v,id2);
            low[x]=min(low[x],low[v]);
        }
        else if(ins[v]){
            low[x]=min(low[x],dfn[v]);
        }
    }
    if(low[x]==dfn[x]){
        if(id!=-1){
            is[id]=1;
            cnt++;
        }
    
        int t;
        do{
            t=st.back();
            st.pop_back();
            ins[t]=0;
        }while(t!=x);
    }
}
void dfs(int x){
    if(x==-1) return;
    if(is[f[x]]){ans=min({ans,u[f[x]],v[f[x]]});}
    dfs(e[x]);
}
void dij(int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    memset(d,0x3f,sizeof(d));
    INF=d[0];
    memset(e,-1,sizeof(e));
    d[s]=0;
    pq.emplace(0,s);
    while(!pq.empty()){
        auto [dis,x]=pq.top();
        pq.pop();
        if(dis>d[x]) continue;
        for(auto [v,id]:g[x]){
            int nd=dis+1;
            if(nd<d[v]){
                d[v]=nd;
                f[v]=id;
                e[v]=x;
                pq.emplace(nd,v);
            }
        }
    }
    if(d[sb]==INF){
        cout<<"No solution\n";
        exit(0);
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    m=1;
    while(cin>>u[m]>>v[m]){
        if(u[m]==v[m]&&v[m]==0)break;
        g[u[m]].emplace_back(v[m],m);
        g[v[m]].emplace_back(u[m],m);
        ++m;
    }
    cin>>sa>>sb;
    // cout<<sa<<" "<<sb<<"\n";
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i,-1);
        }
    }
    cout<<cnt;
    if(cnt==0){
        cout<<"No solution\n";
        return 0;
    }
    dij(sa);
    dfs(sb);
    if(ans==INT_MAX){
        cout<<"No solution\n";
        return 0;
    }
    cout<<ans<<'\n';
    return 0;
}