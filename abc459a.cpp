#include<bits/stdc++.h>
using namespace std;
string s=" HelloWorld";
int main(){
    int x;
    cin>>x;
    for(int i=1;i<s.size();i++){
        if(i!=x) cout<<s[i];
    }
    return 0;
}