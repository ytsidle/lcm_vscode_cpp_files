#include <bits/stdc++.h>
using namespace std;
char win[62503];
int main(){
	char s;
	int i;
	for(i=1;cin>>s&&s!='E';i++)//循环读入，当读到字符E结束 
	{
		if(s=='W')win[i]=1; 
		else win[i]=2; 
	}
	int a=0,b=0,ei=0,num=11;
	int n=i;
	for(i=1;i<=n;i++){
		ei++;
		if(win[i]==1){
			a++;
		}else if(win[i]==2) b++;
		else{
			cout<<a<<":"<<b<<endl;
		}
		
		if(a-b>=2||b-a>=2){
			if(a>=num||b>=num){
				cout<<a<<":"<<b<<endl;
				a=0,b=0,ei=0;
			}
		}
		
	}
	cout<<endl;
	ei=0,num=21,a=0,b=0;
	for(i=1;i<=n;i++){
		ei++;
		if(win[i]==1){
			a++;
		}else if(win[i]==2) b++;
		else{
			cout<<a<<":"<<b<<endl;
		}
		
		if(a-b>=2||b-a>=2){
			if(a>=num||b>=num){
				cout<<a<<":"<<b<<endl;
				a=0,b=0,ei=0;
			}
		}
		
	}
	return 0;
}
