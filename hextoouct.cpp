#include <bits/stdc++.h>
using namespace std;
string hexn,bins,res;
char hexs[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
string bin[16]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
string obin[8]={"000","001","010","011","100","101","110","111"};
int cfp(char c){
    for(int i=0;i<=15;i++){
        if(hexs[i]==c) return i;
    }
}
int sfp(string f){
	for(int i=0;i<=15;i++){
		if(obin[i]==f){
			return i;
		}
	}
}
int main(){
    cin>>hexn;
    for(int i=0;i<hexn.length();i++){
        bins=bins+bin[cfp(hexn[i])];
    }//twoto8
    int num=(3-(bins.length()%3))%3;
    for(int i=1;i<=num;i++){
        bins="0"+bins;
    }
//    cout<<bins<<endl;
    for(int i=0;i<bins.length();i+=3){
		string fs="";
		fs=fs+bins[i];
		fs=fs+bins[i+1];
		fs=fs+bins[i+2];
//		cout<<fs<<" "<<sfp(fs)<<endl;
		res=res+char(sfp(fs)+48);
    }while(res[0]=='0'){
    	res.erase(0,1);
    	cout<<"delete"<<endl;
	}
    cout<<res;
	return 0;
}
