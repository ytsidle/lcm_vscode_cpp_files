#include <bits/stdc++.h>
using namespace std;
int n=9;

int main(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<i<<"*"<<j<<"="<<i*j<<" ";
		}cout<<endl;
	}
	return 0;
}
