#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> v;
	v.push_back(12);
	v.push_back(13);
	vector<int> v1;
	v1.push_back(123);
	v1.push_back(1299);
	v1.push_back(125);
	v1.push_back(11);
//	swap(v1,v); //swap
	reverse(v1.begin(),v1.end());
	cout<<"reverse:";
	for(int i=0;i<v1.size();i++){
		cout<<v1[i]<<" ";
	}cout<<endl;
	
	sort(v1.begin(),v1.end());
	for(int i=0;i<v1.size();i++){
		cout<<v1[i]<<" ";
	}cout<<endl;
	return 0;
}
