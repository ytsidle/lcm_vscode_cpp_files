#include <bits/stdc++.h>
using namespace std;
string a,b,in;
int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},ans;
bool is_ok(string n1,string m1){
	int n=(n1[0]-48)*10+(n1[1]-48);
	int m=(m1[0]-48)*10+(m1[1]-48);
	if(n>=1 && n<=m && m<=mon[n]) return true;
	else return false;
}
int main(){
	cin>>in;
	for(int i=1;i<=2;i++){
		a+=in[i-1];
		b+=in[2+i];
	}
	if(!is_ok(a,"1")){
		if(a[0]>'1'){
			if(a[1]<='2'){
				a[0]=mon[(a[1]-48)]>mon[10+(a[1]-48)]?'0' : '1';
				ans++;
			}else{
				a[0]='0';
				ans++;
			}
		}else if(a[0]=='1'){
			a[1]='0';
			ans++;
		}
	}
	if(!is_ok(a,b)){
		ans++;
	}
	cout<<ans;	
	
	return 0;
}
