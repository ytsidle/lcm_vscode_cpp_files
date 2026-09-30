#include<bits/stdc++.h>
using namespace std;
int n,a[105][105],k[105],f[105][105];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>k[i];for(int j=1;j<=k[i];j++){
            cin>>a[i][j];
            f[a[i][j]][i]=1;
        }
    }
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(f[i][j]) cnt++;
        }cout<<cnt<<" ";
        for(int j=1;j<=n;j++){if(f[i][j]) cout<<j<<' ';}cout<<"\n";
    }
    return 0;
}