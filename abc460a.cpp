#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int main(){
    cin>>n>>m;
    while(m){
        ans++;
        m=n%m;
    }
    cout<<ans;

    return 0;
}