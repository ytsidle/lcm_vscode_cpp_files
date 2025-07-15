#include <bits/stdc++.h>
using namespace std;
int n,k;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	long long sid=floor(n*1.0/k);

	if(n%sid==0){
		for(int i=1;i*sid<=n;i++){
			cout<<(long long)(ceil((i*sid+(i-1)*sid)/2.0))<<endl;
		}
	}else{
		int i=0;
		for(i=1;i*sid<=n;i++){
			cout<<(long long)((i*sid+(i-1)*sid)/2.0)<<endl;
		}
		cout<<(long long)((n+(i-1)*sid+1)/2)<<endl;
	}
	return 0;
}
