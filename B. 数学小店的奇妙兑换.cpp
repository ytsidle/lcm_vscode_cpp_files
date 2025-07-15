#include <bits/stdc++.h>
using namespace std;
int ansl[20010]={};
string shan,yu;
inline string add(string a,int num){
	for(int i=1;i<=num;i++){
		a+="0";
	}
	return a;
}
bool cmp(string a,string b){
	if(a.size()!=b.size()) return a.size()<b.size();
	else{
		return a<b;
	}
}
string del(string a,string b){
	//a-b;
	string ans="";
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int len=max(a.size(),b.size());
	for(int i=a.size()-1;i<len;i++)a+="0";
	for(int i=b.size()-1;i<len;i++)b+="0";
//	cout<<a<<" "<<b;
	int x=0;
	for(int i=0;i<len;i++){
		int t=(a[i]-b[i])-x;
		if(t<0){
			t+=10;
			x=1;
		}else x=0;
		ans+=(t+'0');
	}
	reverse(ans.begin(),ans.end());
	while(ans.size()!=1&&ans[0]=='0'){
		ans.erase(ans.begin());
	}
	return ans;
}
void devide(string a,string b){
	int k=0,s=0,wei=0;
	if(cmp(a,b)||a=="0"){
		cout<<0;
		exit(0);
	}if(a==b){
		cout<<1;
		exit(0);
	}
	string sa=a;
	s=k=b.size();
	wei=a.size()-b.size();
	while(!cmp(a,b)&&a!=b){
		string wdel=add(b,wei);
//		cout<<a<<" d "<<wdel<<endl;
		int cnt=0;
		while(!cmp(a,wdel)){
			a=del(a,wdel);
			cnt++;
		}
		ansl[k]=cnt;
		k++;
//		wei=a.size()-b.size();
		wei--;
	}
//	cout<<s<<" "<<sa.size()<<endl;
	while(ansl[s]==0&&s<sa.size()) s++;
	for(int i=s;i<=sa.size();i++){
//		printf("%d",ansl[i]);
		shan+=(ansl[i]+'0');
//		cout<<ansl[i];
	}
//	cout<<endl<<a;
	yu=a;
}
string madd(string a,string b){

	string ans="";
	
	int len=max(a.length(),b.length());

	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for(int i=a.length();i<len;i++){
		a+='0';
//		cout<<"a";
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
int main(){
//	freopen("drink.in","r",stdin);
//	freopen("drink.out","w",stdout);
	string a,b;
	cin>>a>>b;
	devide(a,b);
//	cout<<shan<<" "<<yu<<endl;
	if(yu=="0"){
		cout<<shan;
	}else{
		cout<<madd(yu,"1")<<" "<<madd(shan,"1")<<endl;
		if(madd(yu,"1")==b){
			cout<<madd(shan,"1");
		}else{
			cout<<shan;
		}
	}
	return 0;
}
