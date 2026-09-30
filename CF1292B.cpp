#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=2e16+100000;
ll n=1,x[100],y[100],ax,ay,bx,by;
int main(){
    cin>>x[1]>>y[1]>>ax>>ay>>bx>>by;
    for(int i=2;i<=100;i++){
        x[i]=ax*x[i-1]+bx;
        y[i]=ay*y[i-1]+by;
        if(x[i]>maxn||y[i]>maxn)break;
        n=i;
    }
    ll xs,ys,t;
    cin>>xs>>ys>>t;
    ll ans=0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            ll dist=abs(xs-x[i])+abs(ys-y[i])+abs(x[i]-x[j])+abs(y[i]-y[j]);
            if(dist<=t)ans=max(ans,abs(j-i)+1);
        }
    }cout<<ans<<endl;
    return 0;
}