#include <bits/stdc++.h>
using namespace std;
long long T,n,ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		while(!(n%2)) n=n/2,ans++;
		while(!(n%3)) n=n/3,ans+=2;
		while(!(n%5)) n=n/5,ans+=3;
		if(n!=1) cout<<-1<<"\n";
		else cout<<ans<<"\n";
		
	}
	return 0;
}
