#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(123);
    v.push_back(12);
    vector<int>::iterator it=v.begin();
    for(;it!=v.end();it++){
        cout<<*it<<endl;
    }
    
    return 0;
}