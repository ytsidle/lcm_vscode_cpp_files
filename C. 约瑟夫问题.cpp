#include <bits/stdc++.h>
using namespace std;
vector<int> t;
int n,m,p;

int main(){
	cin>>n>>m;
//	int p=m-1;
	for(int i=1;i<=n;i++)t.push_back(i);
	while(t.size()>1){
		
		p+=m-1;
		p=p%t.size();
		t.erase(t.begin()+p);
	}
	cout<<t[0];
	return 0;
}
