#include <bits/stdc++.h>
using namespace std;
const int M=3e5+20;
int n,a[M],d[M],g[M],cnt[M];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		g[i]=d[i]=a[i];
	}
	sort(d+1,d+1+n);
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(d+1,d+1+n,a[i])-d;
		cnt[a[i]]++;
	} 
	int ma=0;
	int p=0;
	for(int i=1;i<=n;i++){
		if(cnt[a[i]]==1){
			if(g[i]>=ma){
				p=i;
				ma=g[i];
			}
		}
	}
	cout<<p;
	return 0;
}
