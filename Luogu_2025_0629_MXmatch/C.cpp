#include <bits/stdc++.h>
using namespace std;
#define int long long
/*
给定一个非负整数 $x$，你要经过若干次以下操作将其变成 $y$，求最小代价：

* 选择一个 $0\leq i\leq k$，花费 $a_i$ 代价将 $x$ 加或减 $2^i$。

**注意：你在操作时不需要保证 $x$ 为非负整数。**

## 输入格式

**本题有多组测试数据。**

第一行，一个正整数 $T$，表示测试数据组数。对于每组测试数据：

* 第一行，三个非负整数 $x,y,k$。
* 第二行，$k+1$ 个正整数 $a_0, \ldots, a_k$。

## 输出格式

对于每组测试数据，一行，一个非负整数，表示最小代价。
*/
int T,f[40],a[40],x,y,k,b[40],xt,yt,ans;
void tob(int n){
    //to binary
    ans=0;
    int i=0;
    while(n){
        b[i++]=n%2;
        n/=2;
    }
    //倒过来
    i--;
    for(int j=0;j<=i;j++){
        if(b[j]) ans+=f[i-j];
    }

}
signed main(){
    //input
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while(T--){
        cin>>x>>y>>k;
        memset(a,0x3f,sizeof(a));
        memset(f,0x3f,sizeof(f));
        for(int i=0;i<=k;i++){
            cin>>a[i];
        }
        f[0]=a[0];
        for(int i=1;i<=30;i++){
            f[i]=min(2*f[i-1],a[i]);
            // cout<<f[i]<<" ";
        }
        tob(abs(x-y));
        cout<<ans<<endl;

    }
    return 0;
}