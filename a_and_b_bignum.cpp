#include <bits/stdc++.h>
using namespace std;
string madd(string a,string b){
	if(a=="0"||b=="0"){
		cout<<"in1";
		return "0";
		return "0";
	}cout<<"in";
	string ans="";
	unsigned long long f[5000][5000],t=0;
	long long max=0;
	if(a.length()!=b.length()){
		if(a.length()>b.length()){
			b=string(a.length()-b.length(),'0')+b;
		}else{
			a=string(b.length()-a.length(),'0')+a;
		}
	}
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for(long long i=0;i<b.length();i++){
		for(long long j=0;j<a.length();j++){
			t=(a[i]-'0'+b[i]-'0');
			f[i][j+i]+=t%10;
			f[i][j+i+1]+=t/10;
			max=i+j+1;
		}
	}
	for(long long i=1;i<=b.length();i++){
		for(long long j=0;j<a.length();j++){
			f[i][j]+=f[i-1][j];
			
		}
	}int x=0;
	for(int i=0;i<a.length();i++){
		x=f[b.length()][i];
		f[b.length()][i]=x%10;
		x/=10;
		f[b.length()][i+1]+=x;
		ans+=f[b.length()][i];
	}if(x!=0){
		ans+=f[b.length()][b.length()];
	}
	while(ans[0]=='0'){
		ans.erase(0,1);
	}
	return ans;
}
int main(){
	string a,b;
	cin>>a>>b;
	cout<<a<<" "<<b<<endl;
	cout<<madd(a,b);
	return 0;
}