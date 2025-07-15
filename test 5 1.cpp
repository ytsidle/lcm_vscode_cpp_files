#include <bits/stdc++.h>
using namespace std;
string binary,hexs="";

int main(){
	getline(cin,binary);
	int len=binary.length();
	if(len%4!=0){
		for(int i=1;i<=4-(len%4);i++){
			binary="0"+binary;
		}
	}
	//每四位转一次
	len=binary.length();
	for(int i=(len/4)-1;i>=0;i--){
		string abin=binary.substr(i*4,4);
		unsigned short n=0;
		n+=int(abin[3]-48)*1;
		n+=int(abin[2]-48)*2;
		n+=int(abin[1]-48)*4;
		n+=int(abin[0]-48)*8;
//		cout<<n;
		char ins;
		if(n>=10){
			ins=char(n+55);
//			cout<<ins;
		}else{
			ins=char(n+48);
		}hexs=ins+hexs;
	}cout<<hexs;
	return 0;
}
