#include <bits/stdc++.h>
using namespace std;
const int M=1e5+10;
int n,m,ans[M],vis[M];
vector<int> a[M];
void dfs(int x){
    if(vis[x]) return;
    vis[x]=1;
    for(auto y:a[x]){
        ans[y]=max(ans[x],ans[y]);
        dfs(y);
        
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ans[i]=i;
    }
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        a[y].push_back(x);
    }
    for(int i=n;i>=1;i--){
        dfs(i);
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}