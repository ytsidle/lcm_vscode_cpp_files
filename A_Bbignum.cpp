#include <bits/stdc++.h>
using namespace std;

string madd(string a,string b){

	string ans="";
	
	int len=max(a.length(),b.length());

	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for(int i=a.length();i<len;i++){
		a+='0';
		
	}
	for(int i=b.length();i<len;i++){
		b+='0';
		
	}int x=0;
	for(int i=0;i<len;i++){
		x+=(a[i]-'0')*(b[i]-'0');
		ans += (x%10+'0');
		x/=10;
	}
	if(x!=0){
		len++;
	ans+=char(x+'0');
	}reverse(ans.begin(),ans.end());
//	while(ans[0]=='0'){
//		ans.erase(0,1);
//	}
	return ans;
}
int main(){
	string a,b;
	cin>>a>>b;
	cout<<madd(a,b);
	return 0;
}