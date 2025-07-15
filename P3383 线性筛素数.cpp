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
			
		}for(int j=0;j<prime.size()&&i*prime[j]<=n;j++){
			is[i*prime[j]]=1;
			if(i%prime[j]==0){
				break;
			}
		}
	}
}
int main(){
	cin>>n>>m;
	
	init();
	for(int i=1;i<=m;i++){
		scanf("%d",&q);
		printf("%d\n",prime[q]);
	}

	return 0;
}
