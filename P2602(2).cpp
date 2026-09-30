#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll l, r, f[15][10][10], pw[20];
int a[20];
ll solve(ll x, int num) {
    int cnt = 0;
    while (x) { // 分解数位
        a[++cnt] = x % 10;
        x /= 10;
    }
    ll ans = 0;
    for (int i = cnt - 1; i; --i) { // 位数严格 < x的贡献
        for (int j = 1; j <= 9; ++j) {  // 枚举位数以及最高位是谁
            ans += f[i][j][num];
        }
    }
    for (int i = cnt; i; --i) { // 位数恰好相等，枚举lcp
        if (i == cnt) { // 假如在第一个位置
            for (int j = 1; j < a[i]; ++j) { // [1, a[i])
                ans += f[i][j][num];
            }    
        } else {
            // 考虑(i, len]的固定数位贡献，如果a[j]是num则有贡献，第i位填[0, a[i]), 剩下i - 1位随便填所以是10^{i-1}
            for (int j = cnt; j > i; --j) { 
                ans += (a[j] == num) * a[i] * pw[i - 1];
            }
            for (int j = 0; j < a[i]; ++j) {  // 暴力枚举第i位的数字j, 用dp值统计
                ans += f[i][j][num];
            }
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> l >> r;
    pw[0] = 1;
    for (int i = 1; i <= 15; ++i)
        pw[i] = pw[i - 1] * 10;
    // f[i][j][k]表示i位数，考虑前导0，最高位是i，i这个数字的出现次数
    for (int i = 0; i <= 9; i++)    // dp预处理
        f[1][i][i] = 1; // 只有一位的情况
    for (int i = 2; i <= 13; ++i) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= 9; ++k) {
                for (int d = 0; d <= 9; ++d) {  // [1, i-1]位的贡献
                    f[i][j][k] += f[i - 1][d][k];
                }
            }
            f[i][j][j] += pw[i - 1]; // 新加入的第i位的贡献
        }
    }
    for (int i = 0; i <= 9; ++i)    // 枚举要算的数字，注意因为枚举LCP，所以贡献是(1, x-1)，所以+1
        cout << solve(r + 1, i) - solve(l, i) << " ";
    return 0;
}