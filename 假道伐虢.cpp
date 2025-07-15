#include <bits/stdc++.h>
using namespace std;
int spec=1,n,m,a[2000];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		if(x!=1) spec=0;
	}
	if(m==0){
		cout<<a[1];
		exit(0);
	}else if(spec){
		sort(a+2,a+1+n);
		for(int i=2;i<=n;i++){
			if(a[1]>=a[i]){
				a[1]+=a[i];
			}
		}cout<<a[1];
		exit(0);
	}else{
		//土办法
		long long x=a[1];
		for(int i=2;i<=n;i++){
			if(x>=a[i]){
//				a[1]+=a[i];
				x+=a[i];
			}else break;
		}cout<<x;
		exit(0);
	}
	return 0;
}
