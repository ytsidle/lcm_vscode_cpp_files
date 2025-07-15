#include <bits/stdc++.h>
using namespace std;
const int MAX=2e6+10;
vector<bool> v(MAX);
unordered_map<vector<bool>, int> m;
int n,k,t;
long long ans;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		v[i]=t;
	}
	v[n+1]=0;
	for(int i=1;i<=k;i++){
		if(0){
			ans+=m[v];
		}
		else{
			long long sums=0;
//			vector<bool> tv=v;
			for(int i=1;i<=n;i++){
				if(v[i]!=v[i+1]){
					v[i]=!v[i];
					sums+=2;
				}else sums+=1;
//				cout<<tv[i]<<" ";
			}
//			m[tv]=sums;
			ans+=sums;
		}
	}
	printf("%lld",ans);
	return 0;
}
