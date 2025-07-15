#include <bits/stdc++.h>
using namespace std;
const int M=1e6+10;
struct Data{
	int num,p;
};
Data a[M];
bool cmp(Data a,Data b){
	return a.num<b.num;
}
int l,r,n,lc,rc;
int main(){
	freopen("god.in","r",stdin);
	freopen("god.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].num);
		a[i].p=i;
	}
	sort(a+1,a+1+n,cmp);
//	cout<<a[1]<<" "<<(lower_bound(b+1,b+1+n,a[1])-b);
	l=1,r=n;
	while(l<r){
		lc=1,rc=1;
		for(int i=l+1;i<=r-1;i++){
			if(abs(a[i].num-a[l].num)>abs(a[i].num-a[r].num)){
				lc++;
			}else if(abs(a[i].num-a[l].num)==abs(a[i].num-a[r].num)){
				if(a[l].num>a[r].num) lc++;
				else rc++;
			}else rc++;
		}
		if(lc==rc){
			if(a[l].num>a[r].num) l++;
			else r--;
		}else{
			if(lc>rc) l++;
			else r--;
		}
	}
	printf("%d",a[l].p);
	return 0;
}
