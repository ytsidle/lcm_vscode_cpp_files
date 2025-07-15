#include <bits/stdc++.h>
using namespace std;
const int N=100000+10;
long long v[N],res,s;
int a[N],n,d,mn=1e9;
int main(){
	cin>>n>>d;
	for(int i=1;i<n;i++){
		cin>>v[i];
		s+=v[i];
		if(s%d==0) v[i]=s/d;else v[i]=s/d+1;
	}
	for(int i=1;i<n;i++){
		cin>>a[i];
		mn=min(mn,a[i]);
		res+=mn*(v[i]-v[i-1]);
	}
	cout<<res;
	return 0;
}
