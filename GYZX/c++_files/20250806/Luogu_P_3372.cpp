#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M=2e5+10;
struct tree{
    ll sum,tag;
}tr[M];
ll n,m,a[M],lc[M],rc[M],cnt=1;
void push_up(ll p){
    tr[p].sum=tr[lc[p]].sum+tr[rc[p]].sum;
}
void push_down(ll p,ll l,ll r){
    ll tag=tr[p].tag;
    if(!tag){

    }
}
void update(int p,int l,int r,int L,int R,int val){
    if(!p){
        ++cnt;
    }
    if(L<=l&&r<=R){
        
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    //动态开点

    for(int i=1;i<=m;i++){
        ll op,l,r,x;
        cin>>op>>l>>r;
        if(op==1){
            cin>>x;
            update(1,1,n,l,r,x);
        }else{
            cout<<query(1,1,n,l,r)<<"\n";
        }
    }
    return 0;
}