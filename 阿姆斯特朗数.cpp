#include <bits/stdc++.h>
using namespace std;
bool amtesl(string a){
	long long ans=0;
	for(int i=0;i<a.size();i++){
		ans+=pow(a[i]-'0',a.size());
	}return ans==stoll(a);
}
int main(){
	int m;
	cin>>m;
	string b;
	for(int i=1;i<=m;i++){
		cin>>b;
		if(amtesl(b)){
			cout<<"T\n";
		}else{
			cout<<"F\n";
		}
	}
	return 0;
}
