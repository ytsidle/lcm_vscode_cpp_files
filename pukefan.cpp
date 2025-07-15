#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	cin>>n>>m;
	vector<bool> v(n+10,0);
	for(int i=1;i<=m;i++){
		for(int j=i;j<=n;j+=i){
			v[j]=!v[j];
		}
	}for(int i=1;i<=n;i++){
		if(v[i]==1){
			cout<<i<<" ";
		}
	}
	return 0;
}
