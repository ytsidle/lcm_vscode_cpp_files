#include <bits/stdc++.h>
using namespace std;
long long sum,i,n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		sum+=i*(n-i+1);
	}cout<<sum;
	return 0;
}

