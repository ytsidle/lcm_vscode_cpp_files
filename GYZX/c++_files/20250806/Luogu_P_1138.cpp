
#include <bits/stdc++.h>
using namespace std;
#define ii int
#define ll long long
#define im INT_MAX
#define llm LONG_LONG_MAX
const int N=3e4+10;
int n,tr[4*N],k;
void push_up(int p){
    tr[p]=tr[p<<1]+tr[p<<1|1];
}
void update(ii p,ii l,ii r,ii x){
    if(l==r){
        tr[p]=1;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid) update(p<<1,l,mid,x);
    else update(p<<1|1,mid+1,r,x);
    push_up(p);
}
int query(ii p,ii l,ii r,ii tot){
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(tr[p<<1]>=tot) return query(p<<1,l,mid,tot);
    else return query(p<<1|1,mid+1,r,tot-tr[p<<1]);
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        update(1,1,30000,x);
    }
    // cout<<tr[1]<<"\n";
    if(k>tr[1])cout<<"NO RESULT";
    else cout<<query(1,1,30000,k);
    return 0;
}