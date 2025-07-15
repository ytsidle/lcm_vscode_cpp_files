#include <bits/stdc++.h>
using namespace std;
struct store{
	int m,num;//m is money,num is number;
};
store f[1100];
int n,m,cnt,ans,need;
bool cmp(store a,store b){
	if(a.m!=b.m){
		return a.m<b.m;
	}else{
		return a.num>b.num;
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>f[i].m>>f[i].num;
	}
	sort(f+1,f+1+m,cmp);
//	for(int i=1;i<=m;i++){
//		cout<<f[i].num<<" "<<f[i].m<<endl;
//	}
	for(int i=1;i<=m;i++){
		need=n-cnt;
		if(need==0) break;
		if(need<=f[i].num){
			cnt+=need;
			ans+=need*f[i].m;
		}else{
			cnt+=f[i].num;
			ans+=f[i].num*f[i].m;
		}
	}cout<<ans;
	return 0;
}
