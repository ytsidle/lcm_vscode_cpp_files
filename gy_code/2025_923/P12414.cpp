#include <bits/stdc++.h>
using namespace std;
int sum[100010],n,m,x,T;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m;
		fill(sum+1,sum+1+n,0);
		for(int i=1;i<=n*m;i++){
			cin>>x;
			sum[x]++;
		}
		int flag=1;
		for(int i=1;i<=n;i++)if(sum[i]!=m) flag=0;
		cout<<((flag==0)?"Yes\n":"No\n");
	}
	return 0;
}
