#include <bits/stdc++.h>
using namespace std;
int t,n,f[2500030];//f[i]=0则为红,1则为黄
long long maxs;
double a;
void fun(double a,int t){
    for(int i=1;i<=t;i++){
        long long num=a*i/1*1;
//        printf("\n%d",&num);
        maxs=max(num,maxs);
        f[num]=(f[num]==0 ? 1:0);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>t;
        fun(a,t);
    }
    for(int i=1;i<=maxs;i++){
//        cout<<f[i]<<' ';
        if(f[i]==1){
            cout<<i<<endl;
            exit(0);

        }

    }
    return 0;
}