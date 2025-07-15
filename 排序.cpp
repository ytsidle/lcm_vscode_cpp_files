#include <bits/stdc++.h>
using namespace std;
int n,num,t;
int main(){
	cin>>n;
	vector<vector<int> > v(n+10);
	for(int i=1;i<=n;i++){
		cin>>num;
		for(int j=1;j<=num;j++){
			cin>>t;
			v[i].push_back(t);
		}sort(v[i].begin(),v[i].end());
	}sort(v.begin()+1,v.begin()+n+1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<v[i].size();j++){
			cout<<v[i][j]<<" ";
		}cout<<endl;
	}
	return 0;
}
