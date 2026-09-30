#include <bits/stdc++.h>
#define int long long
using namespace std;

int T,xa,ya,ra,xb,yb,rb;
int dist(int xa,int ya,int xb,int yb){
    return (xa-xb)*(xa-xb)+(ya-yb)*(ya-yb);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>xa>>ya>>ra>>xb>>yb>>rb;
        if(dist(xa,ya,xb,yb)<=(ra+rb)*(ra+rb)&&(ra-rb)*(ra-rb)<=dist(xa,ya,xb,yb)) cout<<"Yes\n";
        else cout<<"No\n";
    }

    return 0;
}