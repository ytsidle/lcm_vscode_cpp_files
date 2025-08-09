#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii int
#define im INT_MAX
#define llm LLONG_MAX
const int N=1e5+5;
ii n,opt[N],xl[N],tmp[N];
ll tr[4*N];
void push_up(ii p){
    tr[p]=tr[p<<1]+tr[p<<1|1];
}
void update(ii p,ii l,ii r,ii x,ll val){
    if(l==r){
        tr[p]+=val;
        return;
    }
    ii mid=(l+r)>>1;
    if(x<=mid){
        update(p<<1,l,mid,x,val);
    }
    else update(p<<1|1,mid+1,r,x,val);
    push_up(p);
}
ll query(int p,int l,int r,int L,int R){\
    if(R<l||L>r) return 0ll;
    if(L<=l&&r<=R){
        return tr[p];
    }
    int mid=(l+r)>>1;
    ll re=0;
    if(L<=mid) re+=query(p<<1,l,mid,L,R);
    if(R>mid)  re+=query(p<<1|1,mid+1,r,L,R);
    return re;
}
ll whi(int p,int l,int r,int x){
        if(l==r) return l;
        int mid=(l+r)>>1;
        if(tr[p<<1]>=x){
            return whi(p<<1,l,mid,x);
        }
        else return whi(p<<1|1,mid+1,r,x-tr[p<<1]);
}
ll pre(ii p,ii l,ii r,ii x){
    if(tr[p]<=0||l>x){
        return -1;
    }
    if(l==r) return l;
    int mid=(l+r)>>1;
    //先右再左
    int res=pre(p<<1|1,mid+1,r,x);
    if(res!=-1) return res;
    return pre(p<<1,l,mid,x);
}
ll pre2(ii p,ii l,ii r,ii x){
    if(tr[p]<=0||r<x){
        return -1;
    }
    if(l==r) return l;
    int mid=(l+r)>>1;
    //先左再右
    int res=pre2(p<<1,l,mid,x);
    if(res!=-1) return res;
    return pre2(p<<1|1,mid+1,r,x);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int kk=0;
    for(int i=1;i<=n;i++){
        cin>>opt[i]>>xl[i];
        if(opt[i]!=4)tmp[++kk]=xl[i];
    }
    sort(tmp+1,tmp+1+kk);
    ii k=unique(tmp+1,tmp+1+kk)-tmp-1;
    for(int i=1;i<=n;i++){
        if(opt[i]!=4)
        xl[i]=lower_bound(tmp+1,tmp+1+k,xl[i])-tmp;
        ii op=opt[i],num=xl[i];
        if(op==1){
            update(1,1,k,num,1);
        }
        if(op==2){
            update(1,1,k,num,-1);
        }
        if(op==3){
            cout<<query(1,1,k,1,num-1)+1<<"\n";

        }
        if(op==4){
            cout<<tmp[whi(1,1,k,num)]<<"\n";
        }
        if(op==5){
            ll res=pre(1,1,k,num-1);
            if(res!=-1)
            cout<<tmp[res]<<"\n";
        }
        if(op==6){
            ll res=pre2(1,1,k,num+1);
            if(res!=-1)
            cout<<tmp[res]<<"\n";
        }
    }
    return 0;
}