#include <bits/stdc++.h>
using namespace std;
const int MAX=3e5+10;
int n,a[MAX],total;
bool f[MAX];
vector<vector<int> > v;
vector<int> b;
void dfs(int p,int sum){
//	cout<<p<<" "<<sum<<endl;
	if(sum>=total&&p<=n+1){
//		for(int i=0;i<b.size();i++){
//			printf("%d ",b[i]*(i%2==0?-1:1));
//		}
		v.push_back(b);
		return;
	}
	if(p==n+1){
		return;
	}
	if(!f[a[p]]){
		if((sum+1)%2==1){
			b.push_back(a[p]*-1);
		}else{
			b.push_back(a[p]);
		}
		f[a[p]]=1;
		dfs(p+1,sum+1);
//		cout<<p<<"c\n";
		b.pop_back();
		f[a[p]]=0;
//		cout<<"SUCESS"<<sum<<"\n";
	}
	dfs(p+1,sum);
}
int main(){
//	freopen("subsequence.in","r",stdin);
//	freopen("subsequence.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	set<int> s(a+1,a+1+n);
	printf("%d\n",total=s.size());
	dfs(1,0);
	sort(v.begin(),v.end());
	for(int i=0;i<v[0].size();i++){
		printf("%d ",v[0][i]*(i%2==0?-1:1));
	}
	return 0;
}
