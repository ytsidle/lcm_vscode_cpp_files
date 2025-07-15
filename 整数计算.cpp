#include <bits/stdc++.h>
using namespace std;
const int MAX=1e7+10,m=11111111;
unsigned long long f[MAX],n,a,b,c,cnt,ans;
bool cmp(unsigned long long a,unsigned long long b){
	return a<b;
}
int main(){
//	scanf("%ulld%ulld%ulld%ulld",&n,&a,&b,&c);
	cin>>n>>a>>b>>c;
	for(unsigned long long i=1;i<=n;i++){
		f[i]=((a*i+b)*i+c)%m;
	}
	sort(f+1,f+1+n,cmp);
	for(unsigned long long i=1;i<=n;i++) {
		if(f[i]!=f[i-1]){
			cnt++;
			ans+=(f[i]*cnt);
//			cout<<f[i]<<endl;
			if(ans>=m) ans%=m;
		}
	}
	cout<<ans;
	return 0;
}