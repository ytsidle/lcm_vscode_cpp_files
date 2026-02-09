#include <bits/stdc++.h>
#define ls (p<<1)
#define rs ((p<<1)|1)
using namespace std;
const int N=3e5+10;
struct Dat{
    int a,id;
}da[N];
bool cmp(Dat aa,Dat bb){
    return aa.a==bb.a?aa.id<bb.id:aa.a<bb.a;
}
int n,d;
int dp[N],f[N];
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
    int mid=(l+r)>>1;
    if(tot<=mid) update(ls,l,mid,tot,val);
    else update(rs,mid+1,r,tot,val);
    pushup(p);
}
int query(int p,int l,int r,int L,int R){
    if(r<L||R<l) return 0;
    if(L<=l&&r<=R) return tr[p];
    int mid=(l+r)>>1,res=INT_MIN;
    if(L<=mid) res=max(res,query(ls,l,mid,L,R));
    if(R>mid) res=max(res,query(rs,mid+1,r,L,R));
    return res;
}
set<int> s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>da[i].a;
        da[i].id=i;
    }
    sort(da+1,da+1+n,cmp);
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    s.insert(da[1].id);
    for(int i=2;i<=n;i++){
        auto pre=s.upper_bound(da[i].id);
        pre=prev(pre,1);
        int pren=*pre;
        cout<<pren<<" ";
        s.insert(da[i].id);

    }
    return 0;
}