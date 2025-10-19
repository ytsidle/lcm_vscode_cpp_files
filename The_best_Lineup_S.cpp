#include <bits/stdc++.h>
using namespace std;

// 生成不进行任何移动时的最优b序列
vector<int> generate_best(const vector<int>& a) {
    int n = a.size();
    vector<int> b,c(0);
    c.resize(n);
    int ma=0;
    for(int i=n-1;i>=0;--i){
        if(a[i]>ma){
            ma=a[i];c[i]=1;
        }
    }
    for(int i=0;i<n;++i){
        if(c[i]==1) b.push_back(a[i]);
    }
    return b;
}

// 比较两个序列的字典序大小
bool is_better(const vector<int>& a, const vector<int>& b) {
    int min_len = min(a.size(), b.size());
    for (int i = 0; i < min_len; ++i) {
        if (a[i] > b[i]) return true;
        if (a[i] < b[i]) return false;
    }
    return a.size() > b.size();
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
        
        // 不进行任何移动时的最优解
        vector<int> best = generate_best(a);
        
        // 尝试所有可能的移动（将位置j的元素移到位置i前）
        for (int j = 1; j < n; ++j) {  // j是要移动的元素位置
            for (int i = 0; i < j; ++i) {  // i是目标位置（移到i之前）
                // 创建移动后的数组
                vector<int> moved;
                // 添加i之前的元素
                for (int k = 0; k < i; ++k) {
                    moved.push_back(a[k]);
                }
                // 添加要移动的元素
                moved.push_back(a[j]);
                // 添加i到j-1的元素
                for (int k = i; k < j; ++k) {
                    moved.push_back(a[k]);
                }
                // 添加j之后的元素
                for (int k = j + 1; k < n; ++k) {
                    moved.push_back(a[k]);
                }
                
                // 生成移动后的最优b序列
                vector<int> current = generate_best(moved);
                
                // 更新最优解
                if (is_better(current, best)) {
                    best = current;
                }
            }
        }
        
        // 输出结果
        for (int num : best) {
            cout << num << " ";
        }
        cout << "\n";
    }
    
    return 0;
}