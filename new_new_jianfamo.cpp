#include <bits/stdc++.h>
using namespace std;
string sub(string a,string b){
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int len=max(a.size(),b.size());
	for(int i=a.length();i<len;i++){
		a=a+'0';
	}
	for(int i=b.length();i<len;i++){
		b=b+'0';
	}int x=0;
	string ans="";
	for(int i=0;i<len;i++){
		x+=(a[i]-48)-(b[i]-48)+10;
		ans+=x%10+'0';
		x=x/10-1;
	}reverse(ans.begin(),ans.end());
	while(ans[0]=='0'){
		ans.erase(0,0);
	}return ans;
}
int main(){
	string a,b;
	cin>>a>>b;
	cout<<sub(a,b);
	return 0;
}
