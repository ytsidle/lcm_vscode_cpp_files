#include <bits/stdc++.h>
using namespace std;
string sub(string a,string b){
	string ans;//存储结果
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	//数字倒置
	int len=max(a.length(),b.length());
	
	for(int i=a.length();i<len;i++){
		a+="0";
	}for(int i=b.length();i<len;i++){
		b+="0";
	}
//	cout<<a<<" "<<b<<endl;//补"0"
	//处理借位
	int x=0;
	for(int i=0;i<len;i++){
		x = x + (a[i]-'0')-(b[i]-'0')+10;
		ans+=x%10+'0';
		x=x/10-1;
	}
	reverse(ans.begin(),ans.end());
	//去前导0
	while(ans[0]=='0'&&ans.length()>1){
		ans.erase(ans.begin());
	}
	return ans;
}
bool isbig(string a,string b){
//	if(strcmp(a,b)==0) return 0;
	if(a.length()!=b.length()) return a.length()>b.length();
	return a>=b;
}
string wan(string a,string b){
	if(isbig(a,b)){
		return sub(a,b);
	}else{
		return "-"+sub(b,a);
	}
}
int main(){
	string a,b;
	
	cin>>a>>b;
	cout<<wan(a,b);
	return 0;
}
