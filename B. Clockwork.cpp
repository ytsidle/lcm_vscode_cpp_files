#include <iostream>
#include <vector>
#include <algorithm>

bool canContinueIndefinitely(const std::vector<int>& clocks) {
    int n = clocks.size();
    
    // 检查相邻时钟的时间差
    for (int i = 0; i < n - 1; ++i) {
        if (std::abs(clocks[i] - clocks[i + 1]) > 1) {
            return false;
        }
    }
    
    // 检查是否有足够的“缓冲”时间
    for (int i = 1; i < n - 1; ++i) {
        if (clocks[i] < std::min(clocks[i - 1], clocks[i + 1]) + 1) {
            return false;
        }
    }
    
    // 检查所有时钟时间是否相同
    bool allSame = true;
    for (int i = 1; i < n; ++i) {
        if (clocks[i] != clocks[0]) {
            allSame = false;
            break;
        }
    }
    
    // 如果所有时钟时间相同，检查它们是否都是偶数
    if (allSame) {
        return clocks[0] % 2 == 0;
    }
    
    return true;
}

int main() {
    int t;
    std::cin >> t; // 读取测试用例的数量

    while (t--) {
        int n;
        std::cin >> n; // 读取时钟的数量
        std::vector<int> clocks(n);
        
        for (int i = 0; i < n; ++i) {
            std::cin >> clocks[i]; // 读取每个时钟的时间
        }
        
        if (canContinueIndefinitely(clocks)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    
    return 0;
}
