#include <bits/stdc++.h>
using namespace std;
using ll = long long;
mt19937_64 rd(time(0));
ll pr[6]={33,97,61,121,141,1101};
// ll base[3]={131,113,137};
inline ll rdm(){
    return 1ll*1e12+pr[rd()%6];

}
const ll N=1e5+10;
ll ha[N],n,tmp[10],hb[N],hc[N];//amod,bmod,abase,bbase
int main(){
    // cout<<rd()<<" \n "<<rd();
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    // ll am=rdm(),bm=rdm(),ab=rdb(),bb=rdb();
    ll mod=rdm(),cnt=0,mod2=rdm(),mod3=rdm();
    for(int i=1;i<=n;i++){
        ll han=1,hbn=1,hcn=1;
        for(int j=1;j<=6;j++){
            cin>>tmp[j];
            han*= (tmp[j]);
            han%=mod;
            hbn*= (tmp[j]);
            hbn%=mod2;
            hcn*= (tmp[j]);
            hcn%=mod3;
        }
        for(int j=1;j<=6;j++){
            han += (tmp[j]);
            han%=mod;
            hbn += (tmp[j]);
            hbn%=mod2;
            hcn += (tmp[j]);
            hcn%=mod3;
        }
        ha[++cnt]=han;
        hb[cnt]=hbn;
        hc[cnt]=hcn;
    }
    sort(ha+1,ha+cnt+1);
    sort(hb+1,hb+cnt+1);
    sort(hc+1,hc+cnt+1);
    for(int i=2;i<=cnt;i++){
        if(ha[i-1]==ha[i]&&hb[i-1]==hb[i]&&hc[i-1]==hc[i]){
            cout<<"Twin snowflakes found.";
            return 0;
        }
    }cout<<"No two snowflakes are alike.";
    return 0;
}