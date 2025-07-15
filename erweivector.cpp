#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	vector<vector<int> > v(n+10);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			v[i].push_back(i*j);
		}
	}for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			cout<<setw(5)<<v[i][j];
		}cout<<endl;
	}
	return 0;
}
