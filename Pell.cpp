#include <bits/stdc++.h>
using namespace std;
string  pl[1004];
string madd(string a,string b){

	string ans="";
	
	int len=max(a.length(),b.length());

	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for(int i=a.length();i<len;i++){
		a+='0';
		cout<<"a";
	}
	for(int i=b.length();i<len;i++){
		b+='0';
		
	}int x=0;
	for(int i=0;i<len;i++){
		x+=a[i]+b[i]-'0'-'0';
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
int c[1000000];
string mul(string a,string b){
	memset(c,0,sizeof(c));
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
void init(){
	pl[1]="1",pl[2]="2";
	for(int i=3;i<=1003;i++){
		pl[i]=madd(mul("2",pl[i-1]),pl[i-2]);
		
	}
}
int main(){
	init();
	int n;
	cin>>n;
	cout<<pl[n];
	return 0;
}