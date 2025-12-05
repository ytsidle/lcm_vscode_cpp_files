#include <bits/stdc++.h>
using namespace std;
int a[200005],n,x,y,b[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=0;
	b[1]=a[1]*y;
	ans+=a[1];
	for(int i=2;i<=n;i++){
		b[i]=a[i]*y;
//		if(a[i]==a[i-1]) continue;
		if((b[i]-b[1])%(y-x)!=0){
			cout<<-1;
			return 0;
		}else{
			int tt=a[i];
			a[i]-=(b[i]-b[1])/(y-x);
			b[i]=a[i]*y+(tt-a[i])*x;
		}
//		cout<<a[i]<<" ";
		ans+=a[i];
	}cout<<ans;
	return 0;
}
