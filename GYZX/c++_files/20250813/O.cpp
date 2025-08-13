#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int n;
int a[N],tr[N*33][2],cnt=1;
inline void insert(int x){
    int p=1;
    for(int i=31;i>=0;i--){
        //枚举位数
        int np=(x>>i)&1;//求出第i位
        if(tr[p][np]==0) tr[p][np]=++cnt;
        p=tr[p][np];
    }
}
int query(int x){
    int p=1,anss=0;
    for(int i=31;i>=0;i--){
        int np=(x>>i)&1;
        if(tr[p][((np==0)?1:0)]!=0){
            anss|=(1<<i);
            // cout<<x<<" "<<np<<" "<<i<<"\n";
            // cout<<x<<" c "<<p<<" "<<np<<"\n";
            p=tr[p][((np==0)?1:0)];
        } 
        else if(tr[p][np]!=0){
            // cout<<x<<" "<<np<<" "<<i<<"\n";
            // cout<<x<<" b "<<p<<" "<<np<<"\n";
            p=tr[p][np];
        } 
    }
    return anss;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        insert(a[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,query(a[i]));
    }cout<<ans;
    return 0;
}