#include <bits/stdc++.h>
using namespace std;
int n,tmp;
long long sum;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>tmp;
		if(tmp>=10) sum+=tmp;
	}cout<<sum;
	return 0;
}
