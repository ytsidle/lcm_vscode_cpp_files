#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Datas{
    int t,x,y;
}d[60500];
int n,m,f[60500];
int dist(int x,int y){
    return abs(d[x].x-d[y].x)+abs(d[x].y-d[y].y);
}
bool cmp(Datas aa,Datas bb){return aa.t<bb.t;}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>d[i].t>>d[i].x>>d[i].y;
    int ans=1;
    for(int i=1;i<=m;i++) f[i]=1;
    for(int i=2;i<=m;i++){
        for(int j=1;j<i;j++){
            if(dist(i,j)<=d[i].t-d[j].t){
                f[i]=max(f[i],f[j]+1);
            }
        }
    }
    for(int i=1;i<=m;i++) ans=max(ans,f[i]);
    cout<<ans;
    return 0;
}