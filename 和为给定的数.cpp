#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int n,a[MAX],m;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}scanf("%d",&m);
	sort(a+1,a+n +1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j&&a[i]+a[j]==m){
				cout<<min(a[i],a[j])<<" "<<max(a[i],a[j]);
				return 0;
			}
		}
	}cout<<"No";
	return 0;
}
