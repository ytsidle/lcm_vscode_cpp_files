// Problem: D. Me When Median Problem
// Contest: Codeforces - Spectral::Cup 2026 Round 2 (Codeforces Round 1100, Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/2229/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;const int N=1e5+10;
int t,n,a[N],b[N];
bool check(int x){
	int aa=0,bb=0,lst=0;
	for(int i=1;i<=n;i++){
		int ta=(a[i]>=x),tb=(b[i]>=x);
		if(ta==tb&&ta==1) aa++;
		if(ta==tb&&ta==1&&lst==1) lst=0;
		if(ta==tb&&ta==0&&lst==0) {
			bb++;lst=1;
		}
	}return aa>bb;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	int l=1,r=2*n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) {
			l=mid+1;
			ans=mid;
		}else r=mid-1;
		
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)solve();
	
	return 0;
}