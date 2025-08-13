#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1e6+133;
ll mod2=1e6+313;
ll base=113,base2=131;
ll n,has[2000],has2[2000];
char s[2000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    set<pair<ll,ll> > ss;
    for(int i=1;i<=n;i++){
        cin>>(s+1);
        int l=strlen(s+1);
        has[0]=has2[0]=0;
        for(int i=1;i<=l;i++){
            has[i]=has[i-1]*base+s[i];
            has[i]%=mod;
            has2[i]=has2[i-1]*base2+s[i];
            has2[i]%=mod2;
        }
        ss.insert({has[l],has2[l]});
    }
    cout<<ss.size();
    return 0;
}