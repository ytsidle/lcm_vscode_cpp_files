#include <bits/stdc++.h>
using namespace std;
vector<int> a[(int)(1e5+10)];
int n,d,ans;
void dfs(int x,int fa,int dep){
    if(dep>d) return;
    if(dep>0) ans++;
    for(auto y:a[x]){
        if(y==fa) continue;
        dfs(y,x,dep+1);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1,0,0);
    cout<<ans;
    return 0;
}