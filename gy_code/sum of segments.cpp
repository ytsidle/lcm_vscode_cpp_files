#include  <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=3e5+10;
int a[N],b[N],c[N],n,q,sq[N],d[N];
inline int suma(int l,int r){
	return b[r]-b[l-1];
}
inline int Q(int l,int r){
	if(r<l) return 0;
	return (c[l]-c[r+1])-(n-r)*suma(l,r);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	for(int i=n;i>=1;i--){
		c[i]=c[i+1]+a[i]*(n-i+1);
	}
	for(int i=1;i<=n;i++){
		sq[i]=sq[i-1]+(n-i+1);
		d[i]=d[i-1]+Q(i,n);
	}
	cin>>q;
//	cout<<"debug:"<<Q(3,n)<<" "<<Q(2,n)<<" "<<Q(3,3)<<"\n";
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		//开始分块
		int lp=lower_bound(sq+1,sq+1+n,l)-sq;
		int rp=lower_bound(sq+1,sq+1+n,r)-sq;
		int ls=l-sq[lp-1]+lp-1;
		int rs=r-sq[rp-1]+rp-1;
//		cout<<(lp==rp)<<" lp: " <<lp<<"  ls: "<<ls<<" rp: "<<rp<<" rs: "<<rs<<"\n";
		if(rp==lp){
			cout<<Q(lp,rs)-Q(lp,ls-1)<<"\n";
			continue;
		}
		int ans=Q(lp,n)-Q(lp,ls-1)+Q(rp,rs);
//		for(int j=lp+1;j<rp;j++){
//			ans+=Q(j,n) ;
//		}
		if(lp+1<=rp-1)ans+=d[rp-1]-d[lp];
		cout<<ans<<"\n";
	}
	return 0;
}