#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],m,n,s,s2;
int main(){
	freopen("gio.in","r",stdin);
	freopen("gio.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i]-1;
		s2+=m-a[i];
	}
	cout<<max(m-s2,1);
	cout<<endl<<min(s+1,m);
	
	return 0;
}
