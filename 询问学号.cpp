#include <bits/stdc++.h>
using namespace std;
int n,m,t;
int main(){
	cin>>n>>m;
	vector<int> v(n+10);
	for(int i=1;i<=n;i++){
		scanf("%d",&v[i]);
	}for(int i=1;i<=m;i++){
		scanf("%d",&t);
		printf("%d\n",v[t]);
	}
	return 0;
}
