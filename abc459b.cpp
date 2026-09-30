#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s[0]<='r') cout<<(s[0]-'a')/3+2;
        else if(s[0]=='s') cout<<7;
        else if(s[0]<='v') cout<<8;
        else cout<<9;
    }
    return 0;
}