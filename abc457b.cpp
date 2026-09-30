#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
vector<int> a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int k; cin>>k;
        a[i].resize(k);
        for(int j=0;j<k;j++){
            cin>>a[i][j];
        }
    }
    int x,y;
    cin>>x>>y;
    cout<<a[x][y-1]<<endl;
    return 0;
}