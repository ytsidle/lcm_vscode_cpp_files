#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+10;
struct Data{
	int mi,ma;
	bool operator < (const Data &a) const{
		return mi==a.mi?ma<a.ma:mi<a.mi;
	}
}d[MAX];
int c[MAX],n,m,dp[MAX];
inline int bfind(int num){
	//find the latest nump <=num (right)
	int l=1,r=m,mid;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(c[mid]<=num) l=mid+1;
		else r=mid-1;
	}return r;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&d[i].mi,&d[i].ma);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&c[i]);
	}
	sort(d+1,d+1+n);
//	cout<<d[n].mi<<" "<<d[n].ma;
	sort(c+1,c+1+m);
	cout<<bfind(19);
	return 0;
}
