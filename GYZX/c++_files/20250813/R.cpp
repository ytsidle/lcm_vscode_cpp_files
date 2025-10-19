#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char s[N];
int nxt[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    // cin>>n;
    scanf("%d",&n);
    scanf("%s",s+1);
    // int n=strlen(s+1);
    for(int i=2,j=0;i<=n;i++){
        j=nxt[i-1];
        while(j&&s[i]!=s[j+1]) j=nxt[j];
        if(s[i]==s[j+1]) j++;
        nxt[i]=j;
    }
    cout << n-nxt[n];
    return 0;
}