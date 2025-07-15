#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
//想法:模拟
int a[MAX],b[MAX],n,alen=0,blen=0,ab=1,bb=1;
string ins;
int check(string input){
	if(input[0]=='I') return 0;
	else if(input[0]=='A') return 1;
	else return 2;
}
int sti(string input){
	int ans=0,t=1;
	for(int i=input.length()-1;i>=0;i--){
		ans+=(input[i]-48)*t;
		t*=10;
	}
	return ans;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		getline(cin,ins);
		if(check(ins)==0){//加号
			cout<<ins.substr(0)<<endl;
			int num=sti(ins.substr(3));
			if(num<=30){
				alen++;
				a[alen]=num;
				sort(a+ab,a+alen+1);
			}else{
				blen++;
				b[blen]=num;
				sort(b+bb,b+blen+1,cmp);
			}
		}else if(check(ins)==1){//A叫号
			if(ab<=alen){
				cout<<a[ab];
				a[ab]=0;
				ab++;
			}else{
				cout<<"NONE";
			}
		}else if(check(ins)==2){//B叫号
			if(bb<=blen){
				cout<<b[bb];
				b[bb]=0;
				bb++;
			}else{
				cout<<"NONE";
			}
		}
	}
	return 0;
}
