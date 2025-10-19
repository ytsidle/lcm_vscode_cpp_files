#include <bits/stdc++.h>
#define ls (p<<1)
#define rs ((p<<1)|1)
using namespace std;
const int N=3e5+10,M=1e6+10;
struct Data {
	int l,r,w;
	bool operator<(const Data &b) const {
		return w<b.w;
	}
} d[N];
int n,m;
struct Tree {
	int tag,ma;
} tr[4*M];
void push_up(int p) {
	tr[p].ma=max(tr[ls].ma,tr[rs].ma);
}
void push_down(int p,int l,int r) {
	int tag=tr[p].tag;
	tr[ls].ma+=tag;
	tr[rs].ma+=tag;
	tr[ls].tag+=tag;
	tr[rs].tag+=tag;
	tr[p].tag=0;
}
void update(int p,int l,int r,int L,int R,int val) {
	if(L<=l&&r<=R) {
		tr[p].ma+=val;
		tr[p].tag+=val;
		return;
	}
	push_down(p,l,r);
	int mid=(l+r)>>1;
	if(L<=mid) update(ls,l,mid,L,R,val);
	if(mid<R)update(rs,mid+1,r,L,R,val);
	push_up(p);
}
int query(int p,int l,int r,int L,int R) {
	if(L<=l&&r<=R) return tr[p].ma;
	push_down(p,l,r);
	int mid=(l+r)>>1,re=INT_MIN;
	if(L<=mid) re=max(re,query(ls,l,mid,L,R));
	if(mid<R)re=max(re,query(rs,mid+1,r,L,R));

	return re;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>d[i].l>>d[i].r>>d[i].w;
	sort(d+1,d+1+n);
	int l=1,r=0,ans=(int)(1e9);
	while(l<=n) {
		if(l>1) {
			update(1,1,m,d[l-1].l,d[l-1].r-1,1);//恢复上一个区间，使其无用
		}
		while(query(1,1,m,1,m-1)==0) {
			r++;
			if(r>n){
				cout<<ans;
				return 0;
			}
			update(1,1,m,d[r].l,d[r].r-1,-1);
		}
		ans=min(ans,d[r].w-d[l].w);
		l++;
	}
	cout<<ans;
	return 0;
}
