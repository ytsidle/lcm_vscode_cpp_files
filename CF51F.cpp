#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2005;
int n,m,dfn[N],low[N],ti,bel[N],vccnt,ins[N],vis[N],sz[N],len,ma[N],tcnt,lcnt,rt,vis2[N];
long long ans=0;
vector<int> g[N],st,g2[N];
int eeer=0;
void out(){
	cout<<++eeer<<" debug\n";
}
void tarjan(int u,int fa){
	dfn[u]=low[u]=++ti;
	st.emplace_back(u);
	ins[u]=1;
	for(int v:g[u]){
        if(v==fa) continue;
		if(!dfn[v]){ 
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
		}else if(ins[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		int y;
		vccnt++;
		int cnt=0;
		do{
			y=st.back();
			cnt++;
			st.pop_back();
			ins[y]=0;
			bel[y]=vccnt;
            // cout<<" y:  "<<y<<" bel: "<<vccnt<<"\n";
		}while(y!=u);
		ans+=cnt-1;
	}
}

void solve(int x,int fa){

	vis[x]=1;
	tcnt++;
	for(auto i:g2[x]){
        if(i!=fa){
            solve(i,x);
            len=max(len,ma[x]+ma[i]+1);
            ma[x]=max(ma[x],ma[i]+1);
        }
    }
    
}
int count(int root,int fa){
    int anss=0,cnt=0;
    vis2[root]=1;
    for(auto i:g2[root]){
        if(!vis2[i]) anss+=count(i,root),cnt++;
    }
    return anss+(cnt==(fa==-1));
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tarjan(i,-1);
		}
	}
//	out();
	for(int i=1;i<=n;i++){
		for(auto v:g[i]){
			if(bel[i]!=bel[v]){
				g2[bel[i]].emplace_back(bel[v]);
				// cout<<bel[i]<<" : "<<bel[v]<<"\n";
			}
		}
	}
//	out();
	int lt=0;
	for(int i=1;i<=vccnt;i++){
		if(!vis[i]){
			lt++;
			lcnt=tcnt=len=0;
		    solve(i,-1);
			len++;
			memset(vis2,0,sizeof(vis2));
			lcnt=count(i,-1);
//			cout<<tcnt<<" LA\n";
			if(tcnt!=1)ans+=tcnt-len-lcnt+2;
            // cout<<i<<" "<<lcnt<<" "<<len<<'\n';
			
		}
	}
//	cout<<lt<<" dd\n";
	cout<<ans+lt-1;
	
	return 0;
};