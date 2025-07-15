#include <bits/stdc++.h>
using namespace std;
char ai,bi,z=char(0);
string in,a,b,res;
int len;
int main() {
    getline(std::cin,a);
    getline(std::cin,b);
    getline(std::cin,in);
//    cout<<a.length();
//    int alen=a.length(),blen=b.length();//
//    if(alen>blen){
//        for(int i=1;i<alen-blen;i++){
//            b='0'+b;
//        }
//    }else{
//        for(int i=1;i<=blen-alen;i++){
//            a='0'+a;
//        }
//    }
//    cout<<a.length()<<" "<<b.length()<<endl;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	len=max(a.length(),b.length());
    if(in=="and"){
        for(int i=0;i<len;i++){
        	ai=(a[i]!=z?a[i]:'0'),bi=(b[i]!=z?b[i]:'0');
            res=res+((ai=='1' && bi=='1')?'1':'0');
//            cout<<res<<endl;
        }
    }else if(in=="or"){
        for(int i=0;i<len;i++){
        	ai=(a[i]!=z?a[i]:'0'),bi=(b[i]!=z?b[i]:'0');
            res=res+((ai=='0'&&bi=='0')?'0':'1');
        }
    }else if(in=="xor"){
        for(int i=0;i<len;i++){
        	ai=(a[i]!=z?a[i]:'0'),bi=(b[i]!=z?b[i]:'0');
            res=res+((ai==bi)?'0':'1');
        }
    }
    reverse(res.begin(),res.end());
    while(res[0]=='0'&&res.length()!=1){
        res.erase(0,1);
//        cout<<"delete"<<endl;
    }
    cout<<res;
    return 0;
}