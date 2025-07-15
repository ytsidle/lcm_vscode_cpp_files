#include <bits/stdc++.h>
using namespace std;

int n,m,no,num;
int main(){
	scanf("%d%d",&n,&m);
	vector<vector<int> > v(n+10);
	for(int i=0;i<m;i++){
		scanf("%d%d",&no,&num);
		v[no].push_back(num);
	}
	for(int i=1;i<=n;i++){
		sort(v[i].begin(),v[i].end());
		cout<<v[i].size()<<" ";
		for(int j=0;j<v[i].size();j++){
			cout<<v[i][j]<<" ";
		}cout<<endl;
	}
	return 0;
}
