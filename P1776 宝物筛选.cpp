#include <bits/stdc++.h>
using namespace std;
int n,k,q[(int)(1e5+10)],q2[(int)(1e5+10)],dp[(int)(1e5+10)];
long long ans=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	int v,w,m;
	for(int i=1;i<=n;i++){
		cin>>v>>w>>m;

		if(w==0){
			ans+=1LL*v*m;
			continue;
		}
		int sz=min(m,k/w);
		// 枚举余数 d
		for(int d=0;d<w;d++) {
			int hh=0,tt=-1; 
			for(int j=0;j*w+d<=k;j++){
				// 移除超出范围的元素
				while(hh<=tt && (j - q[hh]) > sz) hh++;
				// 状态转移，队列为空时不转移
				if(hh<=tt){
					dp[j*w + d]=max(dp[j*w + d], q2[hh] + j * v);
				}
				int val = dp[j*w + d] - j * v;
				// 维护单调队列的单调性
				while(hh<=tt && val >= q2[tt]) tt--;
				tt++;
				q[tt]=j;
				q2[tt]=val;
			}
		}
	}
	// 遍历 dp 数组更新 ans
	for(int i = 0; i <= k; ++i) {
		ans = max(ans, (long long)dp[i]);
	}
	cout<<ans;
	return 0;
}
