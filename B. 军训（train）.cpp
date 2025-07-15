#include <bits/stdc++.h>
using namespace std;
#define M 1000100
int n,a[M];
int main(){
	freopen("train.in","r",stdin);
	freopen("train.out","w",stdout);
	cin>>n;
	int up=2,ans=0;
	a[0]=-1452042;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if((up==2||up==1)&&a[i]==a[i-1]+1) up=1;
		else if((up==2||up==0)&&a[i]==a[i-1]-1) up=0;
		else ans++,up=2;
	}
	cout<<ans-1;
	return 0;
}