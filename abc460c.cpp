#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],b[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];}
    for(int i=1;i<=m;i++){cin>>b[i];}
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    int ans=0;
    for(int l=1,r=1;l<=n&&r<=m;l++){
        if(a[l]*2<b[r]){continue;}
        else{
            r++;
            ans++;
        }
    }cout<<ans;
    return 0;
}