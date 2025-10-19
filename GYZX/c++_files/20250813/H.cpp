#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+10;
int mod = 1e9+39;
int base = 131; 
int n,m,has[N],has2[N],pw[N];
char s[N],s2[N];
int query(int l,int r){
    return (has[r]-(long long)(1ll*has[l-1]*pw[r-l+1]%mod)+mod)%mod;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>(s+1);
    int n=strlen(s+1);
    pw[0]=1;
    for(int i=1;i<=n;i++) {
        has[i]=(1ll*has[i-1]*base+s[i])%mod;
        pw[i]=(1ll*pw[i-1]*base)%mod;
    }
    int T;
    cin>>T;
    while(T--){
        int l,r,l2,r2;
        cin>>l>>r>>l2>>r2;
        if(query(l,r)==query(l2,r2)) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}