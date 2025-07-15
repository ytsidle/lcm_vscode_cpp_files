#include <bits/stdc++.h>
using namespace std;
vector<int> up;
deque<int> down;
int n,x,p;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		down.push_back(x);
	}
	while(!down.empty()){
		up.push_back(down.front());
		down.pop_front();
		if(down.empty())break;
		x=down.front();
		down.pop_front();
		down.push_back(x);
	}
	for(vector<int>::iterator it=up.begin();it!=up.end();it++) cout<<*it<<" ";
	return 0;
}
