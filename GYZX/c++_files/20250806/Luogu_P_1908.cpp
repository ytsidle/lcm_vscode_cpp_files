#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,a[N],cnt;
struct Node{
    int ls,rs,sum;
}tr[6*N];
void push_up(int p){
    tr[p].sum=tr[tr[p].ls].sum+tr[tr[p].rs].sum;
}
void update(int &p,int l,int r,int val){
    if(!p){
        p=(++cnt);
    }
    if(l==r){
        tr[p].sum++;
        return;
    }
    int mid=(l+r)>>1;
    if(val<=mid) update(tr[p].ls,l,mid,val);
    else update(tr[p].rs,mid+1,r,val);
    push_up(p);
}
int query(int p,int l,int r,int L,int R){
    if(!p) return 0;
    if(L<=l&&r<=R) return tr[p].sum;
    int mid=(l+r)>>1;
    int re=0;
    if(L<=mid) re+=query(tr[p].ls,l,mid,L,R);
    if(R>mid)re+=query(tr[p].rs,mid+1,r,L,R);
    return re;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int mx=0;
    for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
    long long ans=0;
    int rt=0;
    for(int i=1;i<=n;i++){
        ans+=query(rt,1,mx,a[i]+1,mx);
        // cout<<query(1,1,mx,a[i]+1,mx)<<" asds \n";
        // int mid=(1+mx)>>1;
        // update(tr[1].ls,1,mid,a[i]);
        // update(tr[1].rs,mid+1,mx,a[i]);
        update(rt,1,mx,a[i]);
    }
    cout<<ans;
    return 0;
}