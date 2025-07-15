#include <bits/stdc++.h>
using namespace std;
#define ll long long
//链式前向星存边
struct Edge{
    ll to,p,next;
}edge[200005];
ll n,m,pre[100005],cnt=0,fa[100005],depth[100005],ans[100005];
void add(ll u,ll v,ll w){
    edge[++cnt].to=v;
    edge[cnt].p=w;
    edge[cnt].next=pre[u]; 
    pre[u]=cnt;
}
bool f[100005];
void dfs(ll u){
    f[u]=1;
    depth[u]=depth[fa[u]]+1; 
    for(ll i=pre[u];i;i=edge[i].next){
        ll v=edge[i].to;
        if(f[v])continue;
        fa[v]=u;
        ans[v]=ans[u]^edge[i].p;
        dfs(v);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(ll i=1;i<n;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w); 
    }
    dfs(1);
    // cout<<"cna\n";
    cin>>m;
    ll u,v,tu,tv;
    for(ll i=1;i<=m;i++){
        
        cin>>u>>v;
        cout<<(ans[u]^ans[v])<<endl;
    }
    return 0;
}
