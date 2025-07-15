#pragma GCC optimize(2)
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

struct Data {
    ll id, num, power;
    bool operator<(const Data& b) const {
        return power > b.power; // 降序排列
    }
};
ll ra[1000010];
bool cmp_num(const Data& a, const Data& b) {
    return a.num < b.num;
}

int main() {
    int n;
    scanf("%d", &n);
    
    vector<Data> a(n+1);       // 数据索引从1开始
    vector<int> is_processed(n+1, 0);
    vector<double> c(n+1, 0.0);
    
    // 读取num值
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i].num);
        a[i].id = i;
        
    }
    
    // 读取power值并检测是否全相同
    bool all_same_power = true;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i].power);
        ra[i]=a[i].power;
        if (a[i].power != a[i-1].power&&i!=1) all_same_power = false;
    }
    
    // 按num升序排序
    
    
    if (all_same_power) {
        for(int i=1;i<=n;i++)
		printf("%lld\n",a[i].power);
        exit(0);
    } else {
        sort(a.begin()+1, a.end(), cmp_num);
        /* 常规处理逻辑（使用multiset优化） */
        multiset<Data> data_set;
        for (int i = 1; i <= n; ++i) {
            data_set.insert(a[i]);
        }
        
        ll k = 0, cnt = 0, sumd = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i].num != a[i-1].num) {
                k += cnt;
                cnt = 1;
            } else {
                is_processed[a[i].id] = 1;
                ++cnt;
                continue;
            }
            
            const ll sum = (n - k) * (a[i].num - sumd);
            sumd = a[i].num;
            if (sum <= 0) continue;
            
            // 清理已处理元素
            auto it = data_set.begin();
            while (it != data_set.end() && is_processed[it->id]) {
                it = data_set.erase(it);
            }
            if (it == data_set.end()) break;
            
            // 获取当前最高power的所有元素
            const ll current_power = it->power;
            auto range = data_set.equal_range(*it);
            
            vector<Data> candidates;
            for (auto rit = range.first; rit != range.second; ++rit) {
                if (!is_processed[rit->id]) {
                    candidates.push_back(*rit);
                }
            }
            data_set.erase(range.first, range.second);
            
            // 分配计算结果
            if (!candidates.empty()) {
                const double unit = (double)sum / candidates.size();
                for (const auto& elem : candidates) {
                    c[elem.id] += unit;
                    if (!is_processed[elem.id]) {
                        data_set.insert(elem);
                    }
                }
            }
            is_processed[a[i].id] = 1;
        }
    }
    
    // 输出结果
    for (int i = 1; i <= n; ++i) {
        printf("%.7lf\n", c[i]);
    }
    
    return 0;
}