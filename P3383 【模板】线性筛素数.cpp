#include <bits/stdc++.h>
using namespace std;
const int MAX=1e8+10;
bool is[MAX];
vector<int> prime;
int n,m,q;
void init(){
	for(int i=2;i<=n;i++){
		if(!is[i]){
			prime.push_back(i);
			for(int j=0;j<prime.size();j++){
				is[i*prime[j]]=1;
			}
		}
	}
}
int main(){
//	cin>>n>>m;
	n=1e2;
	init();
//	for(int i=1;i<=m;i++){
//		scanf("%d",&q);
//		printf("%d\n",prime[q]);
//	}
	for(int i=2;i<=n;i++){
		if(!is[i]) cout<<i<<endl;
	}
	return 0;
}
