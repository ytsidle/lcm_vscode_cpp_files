#include <bits/stdc++.h>
using namespace std;
string a,b;
void emtof(int l,int r,int l2,int r2){
    if(l>r) return;
    cout<<b[r];
    if(l==r) return;
    int pos=a.find(b[r]);
    emtof(l,l+pos-1,l2,l2+pos-1);
    emtof(pos+1,r,l2+pos,r2-1);
}

int main() {
    
    cin>>a>>b;
    emtof(0,a.size()-1,0,b.size()-1);

    return 0;

}