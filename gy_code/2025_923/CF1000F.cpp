#include <bits/stdc++.h>
using namespace std;
#define ls (p<<1)
#define rs ((p<<1)|1)
const int N=5e5+10,INF=1e9+100;
struct Tree {
	int mi,mip;
} tr[4*N];
struct Data {
	int id,l,r,ans;
} asks[N];
struct ret {
	int mi,mip;
};
bool cmp(Data da,Data db) {
	return da.r<db.r;
}
bool cmp2(Data da,Data db) {
	return da.id<db.id;
}
void push_up(int p) {
	tr[p].mi=min(tr[ls].mi,tr[rs].mi);
	if(tr[ls].mi<tr[rs].mi) {
		tr[p].mip=tr[ls].mip;
	} else {
		tr[p].mip=tr[rs].mip;
	}
}
void build(int p,int l,int r) {
	if(l>r)  return;
	if(l==r) {
		tr[p].mi=INF;
		tr[p].mip=l;
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	push_up(p);
}

void update(int p,int l,int r,int idx,int val) {
	if(idx < l || idx > r) return;
	if(l==r) {
		tr[p].mi=val;
		return ;
	}
	int mid =(l+r)>>1;
	if(idx<=mid) update(ls,l,mid,idx,val);
	else update(rs,mid+1,r,idx,val);
	push_up(p);
}
ret query(int p,int l,int r,int L,int R) {
//	if(L>R||l>r) return {INF,-1};
	if(r < L || l > R) {
		return {INF, -1}; // 使用-1表示无效索引
	}
	if(L<=l&&r<=R) {
		ret re;
		re= {tr[p].mi,tr[p].mip};
		return re;
	}
	int mid=(l+r)>>1;
	ret lm=query(ls,l,mid,L,R);
	ret rm=query(rs,mid+1,r,L,R);
	// 处理左子树或右子树查询无效的情况
	if (lm.mip == -1) return rm;    // 左子树无效，返回右子树结果
	if (rm.mip == -1) return lm;    // 右子树无效，返回左子树结果

	// 都有效时比较最小值
	if (lm.mi < rm.mi) {
		return lm;
	} else {
		return rm;
	}
}
int n,q,a[N],lst[N];
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	cin>>q;
	for(int i=1; i<=q; i++) {
		cin>>asks[i].l>>asks[i].r;
		asks[i].id=i;
	}

	sort(asks+1,asks+1+q,cmp);
	asks[0]= {0,0,0,0};
	int l,r;
//	cout<<"fff\n";
	build(1,1,n);
//	cout<<"ff\n";
	for(int rrr=1; rrr<=q; rrr++) {
		//分段
		l=asks[rrr-1].r+1,r=asks[rrr].r;
		for(int i=l; i<=r; i++) {
//			b[lst[a[i]]]=INF;
			if (lst[a[i]] != 0) {
				update(1,1,n,lst[a[i]],INF);
//			b[i]=lst[a[i]];
			}
			update(1,1,n,i,lst[a[i]]);
			lst[a[i]]=i;
		}
//		cout<<"gfff\n";
		ret re = query(1, 1, n, asks[rrr].l, asks[rrr].r);
		if (re.mi >= asks[rrr].l) {
			asks[rrr].ans = 0;
		} else {
			asks[rrr].ans = re.mip;
		}
	}
	sort(asks+1,asks+1+q,cmp2);
	for(int i = 1; i <= q; i++) {
		cout << a[asks[i].ans] << "\n";
	}

	return 0;
}
