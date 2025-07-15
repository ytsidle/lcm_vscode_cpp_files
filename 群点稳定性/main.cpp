#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
const ld PI=3.141592653589793;
const ll N=1e5+10;
ll n;
ld d[N],x[N],y[N],raver;
inline ld dist(ld lk,ld lb,ld x,ld y){
	return abs(lk*x-y+lb)*1.0/sqrt(lk*lk+1.0);
}
ld rtan(ld ang){
	return tan(ang*PI/180.0);
}
ld rcos(ld ang){
    return cos(ang*PI/180.0);
}
ld fc(ld ang){
	ld lk=rtan(ang),lb=0;
	ld aver=0,fc=0;
	for(ll i=1;i<=n;i++){
		d[i]=dist(lk,lb,x[i],y[i]);
		aver+=d[i];
	}
	aver=aver/(n*1.0);
    raver=aver;
	for(ll i=1;i<=n;i++){
		fc+=(d[i]-aver)*(d[i]-aver);
	}
    return fc;
}
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    // scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        // scanf("(%lf,%lf)",&x[i],&y[i]);
    }
    ld l=45,r=-45;
    ld ansang=0,ansfc=1e18,ansaver=0;
    while(r<=l){
        // cout<<r<<" : "<<fixed<<setprecision(16)<<fc(r)<<"\n";
        ld now=fc(r);
        if(now<ansfc){
            ansfc=now;
            ansang=r;
            ansaver=raver;
        }
        r++;
    }
	cout<<"start"<<fixed<<setprecision(16)<<ansang<<" "<<ansfc<<"\n";
    cout<<"dstart:"<<fixed<<setprecision(16)<<fc(-ansang)<<"\n";
    ld ansk=rtan(ansang);
    ld b=raver*1.0/rcos(ansang);
    cout<<"sy="<<fixed<<setprecision(16)<<ansk<<"x+"<<b<<"\n";
    if(ansang==0) return 0;
    int ran=42;  //调整精度
    //重复次数
    ld t=0.25,ad=1.0/180.0;
    r=ansang;
    while(ran--){
        l=r+t;
        r=r-t;
        t*=0.5;
        while(r<=l){
            // cout<<r<<" : "<<fixed<<setprecision(16)<<fc(r)<<"\n";
            ld now=fc(r);
            if(now<ansfc){
                ansfc=now;
                ansang=r;
                ansaver=raver;
            }
            r+=ad;
        }
        ad*=(1.0/2.0);
        r=ansang;
    }
    cout<<"end:"<<fixed<<setprecision(16)<<ansang<<" "<<ansfc<<"\n";
    ansk=rtan(ansang);
    b=raver*1.0/rcos(ansang);
    cout<<"y="<<fixed<<setprecision(16)<<ansk<<"x+"<<b<<"\n";
	return 0;
}
