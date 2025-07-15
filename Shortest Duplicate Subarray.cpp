#include <bits/stdc++.h>
using namespace std;
const int M=1e6+10;
int n,lastp[M],a[M],ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	ans=INT_MAX;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(lastp[a[i]]!=0){
			ans=min(ans,(1+i-lastp[a[i]]));
		}lastp[a[i]]=i;
	}
	if(ans==INT_MAX){
		cout<<-1;
	}else cout<<ans;
	return 0;
}
