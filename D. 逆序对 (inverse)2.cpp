#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAX = 1e9 + 7;
int n, m, a[1010], s[1010][3], b[1010], pos[1010];
LL ans = 0;

// 更新逆序对数量
void update(int i, int j) {
    if (i > j) swap(i, j);
    for (int k = i + 1; k <= j; k++) {
        if (a[k] < a[i]) ans++;
        if (a[k] < a[j]) ans--;
    }
}

// 使用归并排序计算逆序对数量
LL merge_sort(int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) / 2;
    LL inv = merge_sort(l, mid) + merge_sort(mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
            inv += mid - i + 1;
        }
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    for (i = l, k = 0; i <= r; i++, k++) a[i] = b[k];
    return inv;
}

void dfs(int num) {
    if (num == m + 1) {
        ans += merge_sort(0, n - 1);
        return;
    }
    dfs(num + 1);
    swap(a[s[num][1]], a[s[num][2]]);
    update(s[num][1], s[num][2]);
    dfs(num + 1);
    swap(a[s[num][1]], a[s[num][2]]); // 恢复交换
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &s[i][1], &s[i][2]);
        s[i][1] = pos[s[i][1]];
        s[i][2] = pos[s[i][2]];
    }
    dfs(1);
    printf("%lld", ans % MAX);
    return 0;
}
