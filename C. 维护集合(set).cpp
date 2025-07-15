#include <bits/stdc++.h>
using namespace std;
#define M 100010
int f[M],n,q,a[M];
vector<int> factor[100010];
int main(){
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
    for (int i = 1; i <= 100000; i++)
        for (int j = i; j <= 100000; j += i) factor[j].push_back(i);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f[a[i]]++;
	}
	for(int i=1;i<=q;i++){
		int opt,x;
		scanf("%d%d",&opt,&x);
		if(opt==1){
			f[x]--;
		}
		if(opt==2){
			f[x]++;
		}
		if(opt==3){
			int maxn=0;
			for(auto y:factor[x]){
				if(f[y]==0||y==1) continue;
				int  tmp=x,cnt=0;
				while(tmp%y==0){
					tmp/=y;
					cnt++;
				}
				maxn=max(maxn,cnt);
			}
			printf("%d\n",maxn);
		}
	}
	return 0;
}
