#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    long long A, B;
    cin >> N >> A >> B;
    
    unordered_map<long long, long long> count;
    vector<long long> ids;
    ids.reserve(N);
    
    for (int i = 0; i < N; ++i) {
        long long ni, di;
        cin >> ni >> di;
        count[di] = ni;
        ids.push_back(di);
    }
    
    long long total = 0;
    
    for (long long x : ids) {
        long long& cnt_x = count[x];
        if (cnt_x <= 0) continue;
        
        // 先处理外部配对（y > x的情况）
        for (long long s : {A, B}) {
            long long y = s - x;
            if (y <= x) continue; // 确保只处理y > x的情况
            auto it = count.find(y);
            if (it == count.end()) continue;
            long long& cnt_y = it->second;
            
            long long pairs = min(cnt_x, cnt_y);
            total += pairs;
            cnt_x -= pairs;
            cnt_y -= pairs;
        }
        
        // 处理自配对的情况（y == x）
        for (long long s : {A, B}) {
            long long y = s - x;
            if (y != x) continue;
            auto it = count.find(y);
            if (it == count.end()) continue;
            if (y < x) continue; // 确保只处理一次
            
            long long pairs = cnt_x / 2;
            total += pairs;
            cnt_x -= pairs * 2;
            break; // 避免重复处理当A == B的情况
        }
    }
    
    cout << total << endl;
    
    return 0;
}