#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e5+7;

#define ls (p<<1) 
#define rs ((p<<1)|1)
int MAX;
struct Tree{
	int sum=0;
}; 
struct Seg{
	Tree tr[4*M];
	void push_up(int p){
		tr[p].sum=tr[ls].sum&tr[rs].sum;
	}
	void update(int p,int l,int r,int tot,int val){
//		//test
//		tr[tot].sum=val;
//		//real
		//Segment Tree
		if(l==r){
			tr[p].sum=val;
			return ;
		}
		int mid=(l+r)>>1;
		if(tot<=mid){
			update(ls,l,mid,tot,val);
		}else update(rs,mid+1,r,tot,val);
		push_up(p);
	}
	int query(int p,int l,int r,int L,int R){
//		//test
//		int re=tr[l].sum;
//		for(int i=l+1;i<=r;i++){
//			re=(re&tr[i].sum);
//		}
//		return re;
		//-----------real-------------below
		if(L<=l&&r<=R){
			return tr[p].sum;
		}
		int mid=(l+r)>>1,re=MAX;
		if(L<=mid) {
			re&=query(ls,l,mid,L,R);
		}if(mid<R){
			re=re&query(rs,mid+1,r,L,R);
		}
		return re;
	}
}sum2,sum3,sum4;
inline int check_num(int num){
	return num==MAX;
}
inline int lowbit(int num){
	return (-num)&num;
}
inline int counts(int num){
	int re=0;
	while(num){
		num-=lowbit(num);
		re++;
	}
	return re;
}
int n,m,q;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>q;
	MAX=(1<<(n))-1 ;
//	cout<<"MAX: "<<MAX<<endl;
	for(int i=1;i<=m;i++){
		int tsum2=0,tsum3=0,tsum4=0;
		for(int j=1;j<=n;j++){
			char xc;
			cin>>xc;
			if(xc=='1'||xc=='0'){
				tsum2=tsum2*2+(xc-'0');
				tsum3=tsum3*2+(1-(xc-'0'));
				
			}else{
				tsum2=tsum2*2+1;
				tsum3=tsum3*2+1;
			}
			if(xc=='?'){
				tsum4=tsum4*2+1;
			}else tsum4*=2;
		}
		sum2.update(1,1,m,i,tsum2);
		sum3.update(1,1,m,i,tsum3);
		sum4.update(1,1,m,i,tsum4);
	}
	int ans=0;
	for(int i=1;i<=q;i++){
		int op,l,r;
		cin>>op;
		//cout<<i<<" "<<op<<"\n" ;
		if(op==0){
			cin>>l>>r;
//			cout<<tmp1<<" "<<tmp2<<"  ff "<<i<<"\n";
			int tmp3=sum2.query(1,1,m,l,r);
			int tmp4=sum3.query(1,1,m,l,r);
			int tmp5=((tmp3|tmp4));
//			cout<<tmp3<<" "<<tmp4<<" f "<<tmp5<<"\n";
			if(!check_num(tmp5)){
				continue;
			}
			int tmp6=sum4.query(1,1,m,l,r);
			tmp6 = counts(tmp6);
			ans=ans^(1<<tmp6);
//			cout<<tmp6<<" fgf \n" ;
		}else{
			int xx;
			cin>>xx;
			int tsum2=0,tsum3=0,tsum4=0;
			for(int j=1;j<=n;j++){
				char xc;
				cin>>xc;
				if(xc=='1'||xc=='0'){
					tsum2=tsum2*2+(xc-'0');
					tsum3=tsum3*2+(1-(xc-'0'));
				}else{
					tsum2=tsum2*2+1;
					tsum3=tsum3*2+1;
				}
				if(xc=='?'){
					tsum4=tsum4*2+1;
				}else tsum4*=2;
			}
			sum2.update(1,1,m,xx,tsum2);
			sum3.update(1,1,m,xx,tsum3);
			sum4.update(1,1,m,xx,tsum4);
		}
	}
	cout<<ans;
	return 0;
}