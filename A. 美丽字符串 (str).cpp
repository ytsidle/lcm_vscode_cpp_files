#include <bits/stdc++.h>
using namespace std;
string a;
int main(){
	getline(cin,a);
	if(a[0]==a[a.size()-1]){
		cout<<0<<endl;
		return 0;
	}
	for(int i=0;i<a.size()-1;i++){
		if(a[i]==a[i+1]){
			cout<<i+1;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}
