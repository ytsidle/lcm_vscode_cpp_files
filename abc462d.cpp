#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int M = 1e6+10;
int d[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, D;
    cin >> n >> D;

    for (int i = 1; i <= n; ++i) {
        int s, t;
        cin >> s >> t;
        int l = s;
        int r = t - D;
        if (l <= r) {
            d[l]++;
            d[r + 1]--;
        }
    }

    ll ans = 0, cur = 0;
    for (int x = 1; x <= 1e6; ++x) {
        cur += d[x];
        ans += cur * (cur - 1) / 2;
    }

    cout << ans << '\n';
    return 0;
}