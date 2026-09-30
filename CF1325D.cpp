#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll u,v;
int main(){
    cin>>u>>v;
    if(u>v||(v-u)%2){
        cout<<"-1\n";
        return 0;
    }
    if(u==v){
        if(u==0)cout<<"0\n";
        else cout<<"1\n"<<u<<"\n";
        return 0;
    }
    ll de=(v-u)/2;
    if((u&de)==0){
        cout<<"2\n";
        
        cout<<de<<" "<<(de^u)<<"\n";
    }
    else{
        cout<<"3\n";
        cout<<u<<" "<<de<<" "<<de<<"\n";
    }
}