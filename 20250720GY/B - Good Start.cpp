#include <bits/stdc++.h>
using namespace std;
int t,w,h,a,b,x,y,xx,yy;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>w>>h>>a>>b;
		cin>>x>>y>>xx>>yy;
		if(abs(yy-y)%b==0&&abs(xx-x)%a==0||abs(yy-y)%b==0&&abs(yy-y)||abs(xx-x)%a==0&&abs(xx-x)) cout<<"yes\n";
		else cout<<"no\n";
	}
	return 0;
}
