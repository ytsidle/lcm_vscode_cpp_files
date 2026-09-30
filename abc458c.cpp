#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    s=" "+s;
    int n=s.size()-1;
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='C') ans+=min(i-1,n-i)+1;
    }cout<<ans;
    return 0;
} 