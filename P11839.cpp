#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    int idx;
    bool operator<(const Node& other) const {
        if (val == other.val) {
            return idx < other.idx;
        }
        return val > other.val; //字典序最大
    }
};
vector<int> generate_best(const vector<int>& a) {
    int n = a.size();
    vector<Node> b;
    vector<int> res;
    // res.reserve(n);
    b.resize(n);
    for(int i = 0; i < n; ++i) {
        b[i].val = a[i];
        b[i].idx = i;
    }
    sort(b.begin(),b.end());
    int max1=-1,max2=-1,flag=0;
    for(int i=0;i<n;++i){
        // cout<<"val: "<<b[i].val<<" idx: "<<b[i].idx<<"\n";
        // cout<<"max1: "<<max1<<" max2: "<<max2<<"\n";
        if(b[i].idx>max1) {
            res.emplace_back(b[i].val);
            max2=max1;
            max1=b[i].idx;
        }else if(b[i].idx>max2&&flag==0){
            res.emplace_back(b[i].val);
            max1=b[i].idx;
            flag=1;
            // cout<<"flag set to 1\n";
        }
    }
    
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> best = generate_best(a);
        for (int num : best) {
            cout << num << " ";
        }
        cout << "\n";
    }
    
    return 0;
}