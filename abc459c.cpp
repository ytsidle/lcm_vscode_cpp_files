#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int a[N],n,q,tr[N];
int lowbit(int x){
    return -x&x;
}
int query(int x){
    if(x==0) return 0;
    int res=0;
    for(int i=x;i>0;i-=lowbit(i)) res+=tr[i];
    return res;
}
int count(int x){
    if(x<=q)return query(q)-query(x-1);
    else return 0;
}
void update(int x,int v){
    if(x==0) return;
    for(int i=x;i<=q;i+=lowbit(i)) tr[i]+=v;
}
int adn;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=q;i++){
        int opt,x;
        cin>>opt>>x;
        if(opt==1){
            update(a[x],-1);
            update(++a[x],1);
            if(count(adn+1)==n){
                update(1+adn,-query(1+adn));
                adn++;
            }
        }else{
            // cerr<<i<<" "<<adn<<"\n";
            cout<<count(x+adn)<<"\n";
        }
    }
    return 0;
}