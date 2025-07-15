#include <bits/stdc++.h>
using namespace std;
int num[100],k;
char c;
string s;
int main(){
	for(int i=0;i<=12;i++){
		c=getchar();
		s+=c;
		if(c>='0'&&c<='9'){
			num[++k]=c-'0';
		}if(c=='X'){
			num[++k]=10;
		}
	}
	long long sum=0;
	for(int i=1;i<k;i++){
		sum+=num[i]*i;
	}
	if(sum%11==num[k]) cout<<"Right";
	else{
		s.erase(s.size()-1,1);
		cout<<s<<(sum%11==10?'X':char(sum%11+'0'));
	}
	return 0;
}
