#include <bits/stdc++.h>
using namespace std;
int n;
long long sum,last=1;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		
		sum+=last;
		last+=i;
	}cout<<sum;
	return 0;
}
