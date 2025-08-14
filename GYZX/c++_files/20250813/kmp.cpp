#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e6+10;
char s[M],s2[M];
int nxt[M],f[M],n,m;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    scanf("%s%s",s+1,s2+1);
    n=strlen(s+1);
    m=strlen(s2+1);
    //求出nxt
    for(int i=2,j=0;i<=m;i++){
        // int j=nxt[i-1];//s[1...i-1]的Border
        while(j){
            if(s2[j+1]==s2[i]) break;
            j=nxt[j];
        }
        if(s2[i]==s2[j+1]) j++;
        nxt[i]=j;
    }
    // for(int i=1;i<=m;i++) cout<<nxt[i]<<" ";//测试border正确性
    for(int i=1,j=0;i<=n;i++){
        while(j&&(j==m||s[i]!=s2[j+1])){
            j=nxt[j];
        }
        if(s[i]==s2[j+1]) j++;
        f[i]=j;
    }
    for(int i=1;i<=n;i++){
        if(f[i]==m) printf("%d\n",i-m+1);
    }
    // cout<<ans
    for(int i=1;i<=m;i++)printf("%d ",nxt[i]);
    return 0;
}