#include <bits/stdc++.h>
using namespace std;


string devide(string a,int b){
	int yu=0;
	string ans="";
	for(int i=0;i<a.length();i++){
		yu=yu*10+(a[i]-'0');
		ans+=yu/b+'0';
		yu=yu%b;
	}//去前导零
	while(ans[0]=='0'&&ans.length()>1) ans.erase(ans.begin());
	return ans;
}
int main(){
	string a;
	int b;
	cin>>a;
	cin>>b;
	cout<<devide(a,b);
	return 0;
}
