#include <bits/stdc++.h>
#define int long long
int INF=1e18;
using namespace std;
const int N=1e6+10;
int n,q,x[N],a[N][2],b[N][2],xx[N],ff[N];//b is the copy of a
struct Seg{
    #define ls (p<<1)
    #define rs ((p<<1)|1)
    int tr[14*N];
    void push_up(int p){
        tr[p]=min(tr[ls],tr[rs]);
    }
    void build(int p,int l,int r){
        tr[p]=INF;
        if(l==r){
            return;
        }
        int mid=(l+r)>>1;
        build(ls,l,mid);
        build(rs,mid+1,r);
        push_up(p);
    }
    void modify(int p,int l,int r,int tot,int val){
        if(l==r){
            tr[p]=min(tr[p],val);
            return;
        }
        int mid=(l+r)>>1;
        if(tot<=mid){
            modify(ls,l,mid,tot,val);
        }else modify(rs,mid+1,r,tot,val);
        push_up(p);
    }
    int query(int p,int l,int r,int L,int R){
        if(R<L) return INF;
        if(L<=l&&r<=R){
            return tr[p];
        }
        int mid=(l+r)>>1;
        int mi=INF;
        if(L<=mid) mi=min(mi,query(ls,l,mid,L,R));
        if(mid<R)mi=min(mi,query(rs,mid+1,r,L,R));
        return mi;
    }
}sa,sb;
inline int  dist(int x,int y){
    return x>y?x-y:y-x;
}
int tmp[2*N],cnt,dp[N][2];
void add(int id){
    int mmm=min(dp[id][0],dp[id][1]);
    sa.modify(1,1,cnt,b[id][0],mmm-a[id][0]);
    sa.modify(1,1,cnt,b[id][1],mmm-a[id][1]);
    sb.modify(1,1,cnt,b[id][0],mmm+a[id][0]);
    sb.modify(1,1,cnt,b[id][1],mmm+a[id][1]);
}
void out(){
    for(int i=1;i<=cnt;i++) cout<<sa.query(1,1,cnt,i,i)<<" ";
    cout<<"\n";
    for(int i=1;i<=cnt;i++) cout<<sb.query(1,1,cnt,i,i)<<" ";
    cout<<"\n";
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q>>x[0];
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1];
        dp[i][0]=dist(x[0],a[i][0]);
        dp[i][1]=dist(x[0],a[i][1]);
        tmp[++cnt]=a[i][0];
        tmp[++cnt]=a[i][1];
    } for(int i=1;i<=q;i++){
        cin>>x[i];
        tmp[++cnt]=x[i];
    }
    sort(tmp+1,tmp+1+cnt);
    cnt=unique(tmp + 1, tmp + cnt + 1) - (tmp + 1);
    for(int i=1;i<=n;i++){
        b[i][0]=lower_bound(tmp+1,tmp+1+cnt,a[i][0])-tmp;
        b[i][1]=lower_bound(tmp+1,tmp+1+cnt,a[i][1])-tmp;
        // cout<<b[i][0]<<" "<<b[i][1]<<"\n";
    }
    for(int i=1;i<=q;i++){
        xx[i]=lower_bound(tmp+1,tmp+1+cnt,x[i])-tmp;
        // cout<<xx[i]<<" d \n";
    }
    sa.build(1,1,cnt);sb.build(1,1,cnt);//sa:dp[j]-a[j][..] sb:dp[j]+a[j][...] #init
    // dp[1][0]=dist(x[0],a[1][0]);dp[1][1]=dist(x[0],a[1][1]);
    // ff[1]=min(dp[1][0],dp[1][1]);
    add(1);
    // out();
    for(int i=2;i<=n;i++){
        /*
        1.X(j,0)<X(i,0) 
        2.X(j,0)>X(i,0) 

        */
        int ln=sa.query(1,1,cnt,1,b[i][0])+a[i][0];
        int rn=sa.query(1,1,cnt,1,b[i][1])+a[i][1];
        ln=min(ln,sb.query(1,1,cnt,b[i][0],cnt)-a[i][0]);
        rn=min(rn,sb.query(1,1,cnt,b[i][1],cnt)-a[i][1]);
        dp[i][0]=min(dp[i][0],ln);
        dp[i][1]=min(dp[i][1],rn);
        // cout<<ln<<" "<<rn<<" dp\n";
        add(i);
        // out();
    }
    sa.build(1,1,cnt);sb.build(1,1,cnt);//another use
    for(int i=1;i<=n;i++){
        add(i);
    }
    for(int i=1;i<=q;i++){
        int ln=sa.query(1,1,cnt,1,xx[i])+x[i];
        int rn=sb.query(1,1,cnt,xx[i],cnt)-x[i];
        // cout<<ln<<" "<<rn<<" dp22\n";
        cout<<min({ln,rn,dist(x[i],x[0])})+n-1<<"\n";
    }
    return 0;
}