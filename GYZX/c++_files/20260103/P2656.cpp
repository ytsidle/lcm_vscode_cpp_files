#include <bits/stdc++.h>
using namespace std;
int n,m;
struct Edge{
    int u,v,w,all;
};
vector <Edge> edges;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int u,v,w,al,all;
        float att;
        cin>>u>>v>>w>>att;
        edges.push_back({u,v,w,al});
        al=att*10;

    }
    return 0;
}