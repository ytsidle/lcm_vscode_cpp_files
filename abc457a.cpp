#include<bits/stdc++.h>
using namespace std;
int a[120],n,x;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cin>>x;
    cout<<a[x]<<endl;
    return 0;
}