#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int M=3e5+10;
int a[M],n,num[M],ans[M],le,bf,m[M];
bool check(int nu){
	memset(m,0,sizeof(m));
	for(int i=1;i<=nu;i++){
		if(m[num[i]])return 0;
		m[num[i]]=1;
	}return 1;
}
void dfs(int c,int sum){
	if(c>n){
		if(sum==0) return ;
		if(sum>=le){
			if(check(sum)){
//				for(int i=1;i<=sum;i++)cout<<num[i]<<" ";
//				cout<<"\n";
				if(sum>le){
					for(int i=1;i<=sum;i++) ans[i]=num[i];
					le=sum;
				}else{
					int flag=1;
					for(int i=1;i<=sum;i++){
						if(i%2==1&&(-num[i])<(-ans[i])){
							flag=1;
							break;
						}if(i%2==0&&num[i]<ans[i]){
							flag=1;
							break;
						}
						if(i%2==1&&(-num[i])>(-ans[i])){
							flag=0;
							break;
						}if(i%2==0&&num[i]>ans[i]){
							flag=0;
							break;
						}
					}
					if(flag){
						for(int i=1;i<=sum;i++) ans[i]=num[i];
					}
				}
			}
		}
		return;
	}
	dfs(c+1,sum);
	num[sum+1]=a[c];
	dfs(c+1,sum+1);
}
signed main(){
	freopen("subsequence.in","r",stdin);
	freopen("subsequence.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<le<<"\n";
	for(int i=1;i<=le;i++) cout<<ans[i]<<" ";
	return 0;
}