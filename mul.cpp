#include <bits/stdc++.h>
using namespace std;
int c[1000000];
string mul(string a,string b){
	string ans;

	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	
	//计算

	 for(int i=0;i<a.length();i++){
	 	for(int j=0;j<b.length();j++){
 			c[i+j]+=(b[j]-'0')*(a[i]-'0');
 			c[i+j+1]+=c[i+j]/10;
 			c[i+j]%=10;
 			
		}
	 }
	int len=a.size()+b.size();
	//去前导零
	while(c[len]==0&&len>0){
		len--;
	}
	for(int i=len;i>=0;i--){
		ans+=c[i]+'0';
	}
	return ans;
}
int main(){
	string a,b;
	cin>>a>>b;
	cout<<mul(a,b);
	return 0;
}

