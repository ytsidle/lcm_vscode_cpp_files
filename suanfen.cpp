#include <bits/stdc++.h>
using namespace std;
int n,t,cnt;
int main(){
	cin>>n;
	vector<int> v(n+10);
	for(int i=1;i<=n;i++){
		cin>>t;
		v[i]=t;
	}
	sort(v.begin()+1,v.begin()+1+n);
	for(int i=2;i<n;i++){
		cnt+=v[i];
	}printf("%.2f",cnt*1.0/(n-2));
	return 0;
}
