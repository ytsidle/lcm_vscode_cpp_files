#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
const ll N=1e5+10;
using pii=pair<ld,ld>;
pii p[N];
ld mix,miy;
ll n;
inline ld dist(ld lk,ld lb,ld x,ld y){
	return abs(lk*x-y+lb)*1.0/sqrt(lk*lk+1.0);
}
ld f(ld k){
	ld b=miy-k*mix;
//	cout<<k<<"  g  "<<b<<"  j  ";
    ld ans=0;
    for(ll i=1;i<=n;i++){
//        ans+=dist(k,b,p[i].first,p[i].second);
		ans+=abs(k*p[i].first+b-p[i].second);
    }
//    cout<<ans*ans*14<<" \n";
    return ans*ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    mix=0,miy=0;
    for(ll i=1;i<=n;i++){
        cin>>p[i].first>>p[i].second;
        mix+=p[i].first;
        miy+=p[i].second;
    }
    mix/=n;
    miy/=n;
    ld l=1e9+10,r=-1e9-10,lmid=1e9+10,rmid=-1e9-10;
    for(ll i=1;i<=(5e6);i++){
        //三分法
        lmid=l+(r-l)/3;
        rmid=r-(r-l)/3;
//        cout<<f((lmid+rmid)/2)<<"e \n";
        if(f(lmid)<f(rmid)){
            r=rmid;
        } else {
            l=lmid;
        }
    }
    ld k=(lmid+rmid)/2;
    cout<<fixed<<setprecision(16)<<k<<"\n";
    cout<<"y="<<fixed<<setprecision(16)<<k<<"x+"<<miy-k*mix<<"\n";
    return 0;
}