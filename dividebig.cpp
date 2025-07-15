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
int compare(string a,string b){
	if(a.length()<b.length()) return -1;
	if(a.length()>b.length()) return 1;
	if(a==b) return 0;
	if(a>b) return 1;
	
	else return -1;
}
string div(string a,string b){
	int lc=a.length()-b.length()+1,tn=0;
	string ans="",tmp="";
	if(a=="0") return "0";
	for(int i=lc;i>=1;i--){
		tmp=b;
		tn=0;
		//补位
		for(int j=1;j<=i-1;j++) tmp+='0';
//		cout<<"tmp:"<<tmp<<endl;
		while(compare(a,tmp)==1||compare(a,tmp)==0){
			tn++;
			a=sub(a,tmp);
//			cout<<a<<endl;
		}ans+=(tn+'0');
	
	}
	return ans;
}
int main(){
	string a,b,c;
	cin>>a>>b;
	c=a;
	cout<<div(a,b);
	return 0;
}
