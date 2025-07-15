#include <bits/stdc++.h>
using namespace std;
const int M=1e5+10;
long long n,k,a[M],ans,mp=0,maxs=LONG_LONG_MIN;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>0) a[i]-=(ceil(a[i]*1.0/k)*k);
		if(a[i]>=maxs){
			mp=i;
			maxs=a[i];
		}
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]) ans++;
	}cout<<mp<<" "<<ans; 
	return 0;
}
