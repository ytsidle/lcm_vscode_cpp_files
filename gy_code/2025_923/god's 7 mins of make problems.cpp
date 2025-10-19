#include <bits/stdc++.h>
using namespace std;
#define ii unsigned long long 
#define ls (p<<1)
#define rs ((p<<1)|1)

const ii N=1e5+10;
struct Tree{
	ii ma,sum;
}tr[4*N];
ii n,q;
void push_up(ii p){
	tr[p].sum=tr[ls].sum+tr[rs].sum;
	tr[p].ma=max(tr[ls].ma,tr[rs].ma);
}
void build(ii p,ii l,ii r){
	if(l==r){
		cin>>tr[p].ma;
		tr[p].sum=tr[p].ma;
		return;
	}
	ii mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	push_up(p);
}
void update(ii p,ii l,ii r,ii L,ii R){
	if(tr[p].ma==1) return;
	if(l==r){
		tr[p].sum=(ii)sqrt(tr[p].sum);
		tr[p].ma=tr[p].sum;
		return;
	}
	ii mid=(l+r)>>1;
	if(L<=mid) update(ls,l,mid,L,R);
	if(mid<R) update(rs,mid+1,r,L,R);
	push_up(p);
}
ii query(ii p,ii l,ii r,ii L,ii R){
	if(L<=l&&r<=R){
		return tr[p].sum;
	}
	ii mid=(l+r)>>1,ans=0;
	if(L<=mid) ans+=query(ls,l,mid,L,R);
	if(mid<R)  ans+=query(rs,mid+1,r,L,R);
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	build(1,1,n);
	cin>>q;
	while(q--){
		ii k,l,r;
		cin>>k>>l>>r;
		if(!k){
			update(1,1,n,l,r);
		}else cout<<query(1,1,n,l,r)<<"\n";
	}
	return 0;
}
