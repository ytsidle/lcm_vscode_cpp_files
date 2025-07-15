#include <bits/stdc++.h>
using namespace std;
int k,l,r,sum;//这是变量
int main(){
	cin>>k>>l>>r;
	for(int i=l;i<=r;i++){
		if(i%10==k||i%k==0){
			sum+=i;
		}
	}cout<<sum;
	return 0;
}
