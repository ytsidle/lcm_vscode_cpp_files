#include <bits/stdc++.h>
using namespace std;
long long n,mins=LONG_LONG_MAX,maxs=LONG_LONG_MIN,t;
int main(){
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>t;
		if(t<mins){
			mins=t;
		}if(t>maxs){
			maxs=t;
		}
	}cout<<maxs-mins<<endl;
//	cout<<maxs<<" "<<mins;
	return 0;
}
