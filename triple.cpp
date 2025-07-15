#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int nums[MAX],ma,n;
long long ans;
vector<int> HASH[114514];
inline int has(int num,int fro,int fro2){
	int p=(num+14)%114515;
	for(auto k:HASH[p]){
		if(nums[k]==num&&k!=fro&&k!=fro2) return k;
		if(nums[k]>num) break;
	}
	return -1;
}
inline int counts(int num){
	int p=(num+14)%114515,cnt=0;
	for(auto k:HASH[p]){
		if(nums[k]==num) cnt++;
		if(nums[k]>num) break;
	}
	return cnt;
}
int main(){
//	freopen()
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&nums[i]);

	}
	sort(nums+1,nums+1+n);
	for(int i=1;i<=n;i++){
		int p=(nums[i]+14)%114515;
		HASH[p].push_back(i);
	}
	ma=nums[n];
	for(int i=1;i<=n;i++){
		if(counts(nums[i])>=3){
			ans++;
		}
		for(int b=2;1ll*nums[i]*b*b<=ma;b++){
			int numa=nums[i]*b,numb=numa*b;
			numa=has(numa,i,i),numb=has(numb,i,numa);
			if(numa!=-1&&numb!=-1&&numa!=numb){
				ans++;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
