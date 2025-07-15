#include <bits/stdc++.h>
using namespace std;
int n,cnt=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cnt%=26;
			cout<<char('A'+cnt);
			cnt++;
		}cout<<endl;
	}
	return 0;
}
