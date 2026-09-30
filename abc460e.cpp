#include<bits/stdc++.h>
#define int long long
const int mod=998244353;
using namespace std;
int T;
int counta(int k, int mod,int n) {
    if (mod == 1) return 0;         
    if (k == 1) return min(n, mod - 1);  
    int d = __gcd(k - 1, mod);
    int step = mod / d;               
    int limit = min(n, mod - 1); 
    return limit / step;
}
long long countn(int h) {
    if (h <= 0) return 0;
    long long result = 9;          // 9 × 10^(h-1)
    for (int i = 1; i < h; ++i) {
        result *= 10;
    }
    return result;
}
int countDigits(int num) {
    int count = 0;
    if (num == 0) return 1; // 特殊情况：0只有一位
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        int ans=0,po=10;
        for(int h=1;h<=countDigits(n)-1;h++){
            ans+=counta(po,m,n)*countn(h)%mod;
            cerr<<counta(po,m,n)<<"\n";
            ans=(ans%mod+mod)%mod;
            po*=10;
        }cout<<ans<<"\n";
    }
    return 0;
}