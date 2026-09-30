#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int n,mix[N],miy[N];
int x[N],y[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        mix[x[i]]=y[i];
        miy[y[i]]=x[i];
    }
    for(int i=2;i<=n;i++){
        mix[i]=min(mix[i-1],mix[i]);
        miy[i]=min(miy[i-1],miy[i]);
    }int ans=0;
    for(int i=1;i<=n;i++){
        if(mix[x[i]]>=y[i]&&miy[y[i]]>=x[i])ans++;
    }cout<<ans;
    return 0;
}