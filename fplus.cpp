#include <bits/stdc++.h>
using namespace std;
int al[60000],bl[60000],cl[60000];
string fplus(string a,string b){
	int maxs=max(a.length(),b.length());
	for(int i=a.length();i<=maxs;i++) a="0"+a;
	for(int i=b.length();i<=maxs;i++) b="0"+b;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for(int i=0;i<maxs;i++)al[i]=a[i]-48;
	for(int i=0;i<maxs;i++)bl[i]=b[i]-48;
	for(int i=0;i<maxs;i++){
		cl[i]=al[i]-bl[i];
		if(cl[i]<0){
			cl[i]=10+cl[i];
			cl[i+1]-=1;
		}
	}
	string ans="";
//	if(cl[max]<0){
//		ans="-";
//	}
	for(int i=maxs-1;i>=0;i--){
//		cout<<cl[i];
		ans+=cl[i]+'0';
	
	}
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
		return fplus(a,b);
	}else{
		return "-"+fplus(b,a);
	}
}
int main(){
	string a,b;
	cin>>a>>b;
	cout<<wan(a,b);
	return 0;
}
