#include <bits/stdc++.h>
using namespace std;
long long n,ans;
int main(){
	cin>>n;
	for(int i=0;i<=ceil(sqrt(n))+0;i++){
		if((double(sqrt(n-i*i)))==1.0*(long long)(sqrt(n-i*i))){
			if(sqrt(n-i*i)>=(n/2)){
				ans+=2;
			}else ans++;
		}
	}cout<<ans;
	return 0;
}
