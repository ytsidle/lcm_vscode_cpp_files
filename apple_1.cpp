#include <bits/stdc++.h>
using namespace std;
int n,sum,ans=0;
int main(){
	cin>>n;
	while(n>0){
		sum++;
//		cout<<n<<endl;
		if(n%3==1 && !ans){
			ans=sum;
//			cout<<ans<<endl;
		}
		n-=(floor((n-1)/3)+1);

	}
	cout<<n+sum<<" "<<ans;
	return 0;
}
