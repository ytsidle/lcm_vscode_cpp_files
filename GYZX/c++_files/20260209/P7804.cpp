#include <bits/stdc++.h>
#define ls (p*2)
#define rs (p*2+1)
using namespace std;
const int N=3e5+10;
struct Dat{
    int a,id;
}da[N];
bool cmp(Dat aa,Dat bb){
    return aa.a==bb.a?aa.id<bb.id:aa.a<bb.a;
}
int n,d;
int f[N];
int tr[4*N];
int find(int x){
    return f[x]==x?f[x]:f[x]=find(f[x]);
}
void pushup(int p){
    tr[p]=max(tr[ls],tr[rs]);
}
void update(int p,int l,int r,int tot,int val){
    if(l==r){
        tr[p]=val;
        return;
    }
    int mid=(l+r)/2;
    if(tot<=mid) update(ls,l,mid,tot,val);
    else update(rs,mid+1,r,tot,val);
    pushup(p);
}
int query(int p,int l,int r,int L,int R){
    if(r<L||R<l) return 0;
    if(L<=l&&r<=R) return tr[p];
    int mid=(l+r)/2;
    int res=0;
    if(L<=mid) res=max(res,query(ls,l,mid,L,R));
    if(R>mid) res=max(res,query(rs,mid+1,r,L,R));
    return res;
}
set<int> s;
void merge(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx!=fy) {
        f[max(fx,fy)]=min(fx,fy);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>da[i].a;
        da[i].id=-i;
    }
    sort(da+1,da+1+n,cmp);
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    s.insert(da[1].id);
    int ans=0;
    for(int i=1;i<=n;i++){
        int x=-da[i].id;
        auto pos=s.insert(x).first;
        if(pos!=s.begin()&&*pos-*prev(pos)<=d) merge(*pos,*prev(pos));
        if(next(pos)!=s.end()&&*next(pos)-*pos<=d) merge(*pos,*next(pos));
        int ttmp=query(1,1,n,find(x),x)+1;
        ans=max(ans,ttmp);
        update(1,1,n,x,ttmp);
    }
    // for(int i=1;i<=n;i++) cerr<<i<<" "<<f[i]<<"\n";
    // for(int i=1;i<=n;i++){
    //     if(f[i]==i) cerr<<i<<" "<<mi[i]<<" "<<dp[i]<<" \n";
    // }
    cout<<ans;
    return 0;
}