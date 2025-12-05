#include<bits/stdc++.h>
using namespace std;
//二分x,大于x 1,小于x 0.线段树为维护
const int N=1e5+10;
struct Tr{
    int sum,tag;//sum表示区间1的个数
}tr[4*N];
int n,m,a[N],opp[N],ll[N],rr[N],q;
void push_up(int p){
    tr[p].sum=tr[p<<1].sum+tr[p<<1|1].sum;
}
void build(int p,int l,int r,int x){
    if(l==r){
        if(a[l]>=x)tr[p].sum=1;
        else tr[p].sum=0;
        tr[p].tag=-1;
        return;
    }
    int mid=(l+r)>>1;
    build(p<<1,l,mid,x);
    build(p<<1|1,mid+1,r,x);
    push_up(p);
    tr[p].tag=-1;
}
void push_down(int p,int l,int r){
    if(tr[p].tag!=-1){
        int mid=(l+r)>>1;
        tr[p<<1].sum=tr[p].tag*(mid-l+1);
        tr[p<<1|1].sum=tr[p].tag*(r-mid);
        tr[p<<1].tag=tr[p].tag;
        tr[p<<1|1].tag=tr[p].tag;
        tr[p].tag=-1;
    }
}
void update(int p,int l,int r,int L,int R,int val){
    if(L<=l&&r<=R){
        tr[p].sum=val*(r-l+1);
        tr[p].tag=val;
        return;
    }
    push_down(p,l,r);
    int mid=(l+r)>>1;
    if(L<=mid)update(p<<1,l,mid,L,R,val);
    if(R>mid)update(p<<1|1,mid+1,r,L,R,val);
    push_up(p);
}
int query(int p,int l,int r,int L,int R){
    if(L<=l&&r<=R){
        return tr[p].sum;
    }
    push_down(p,l,r);
    int mid=(l+r)>>1,ans=0;
    if(L<=mid)ans+=query(p<<1,l,mid,L,R);
    if(R>mid)ans+=query(p<<1|1,mid+1,r,L,R);
    return ans;
}
bool check(int x){
    //>=x
    build(1,1,n,x);
    for(int i=1;i<=m;i++){
        int l=ll[i],r=rr[i],op=opp[i];
        if(op==0){
            //升序
            int one=query(1,1,n,l,r);
            int zero=r-l+1-one;
            update(1,1,n,l,l+zero-1,0);
            update(1,1,n,l+zero,r,1);

        }else{
            //降序
            int one=query(1,1,n,l,r);
            int zero=r-l+1-one;
            update(1,1,n,l,l+one-1,1);
            update(1,1,n,l+one,r,0);
        } 
    }   
    return query(1,1,n,q,q);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //维护两种操作
    //1.区间查询1,0个数
    //2.区间修改为1/0
    for(int i=1;i<=m;i++){
        cin>>opp[i]>>ll[i]>>rr[i];
    }
    cin>>q;
    int l=1,r=n,mid;
    while(l<r){
        mid=(l+r)>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout<<l<<"\n";
    return 0;
}