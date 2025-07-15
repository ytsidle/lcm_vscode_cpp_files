#include <bits/stdc++.h>
using namespace std;
const int M=2e5+10;
long long n,u[M],d[M],mi=LONG_LONG_MAX;
__int128 ans=0;
void write(__int128 wri){
	if(wri<0) {
		putchar('-');
		wri=-wri;
	}
	if(wri>9)write(wri/10);
	putchar((wri%10)+'0');
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>d[i];
		mi=min(mi,u[i]+d[i]);
	}
	for(int i=1;i<=n;i++){
		ans+=u[i]+d[i]-mi;
	}write(ans);
	return 0;
}
