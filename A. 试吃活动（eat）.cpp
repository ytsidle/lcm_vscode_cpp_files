#include <bits/stdc++.h>
using namespace std;
const int M=2e5+10;
int T,n,a[M],ans,f[M];
vector<int> v;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("eat.in","r",stdin);
	freopen("eat.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		memset(f,0,sizeof(f));
		v.clear();
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]||a[i-1]==a[i-2]){
				if(f[a[i-1]]==0){
					ans++;
					f[a[i-1]]=1;
					v.emplace_back(a[i-1]);
				}
			}else if(a[i]==a[i-2]){
				if(f[a[i]]==0){
					ans++;
					f[a[i]]=1;
					v.emplace_back(a[i]);
				}
			}
		}
		sort(v.begin(),v.end());
		if(ans==0) cout<<"-1\n";
		else{
			for(int x:v) cout<<x<<" ";
			cout<<endl;
		}
	}
	return 0;
}
