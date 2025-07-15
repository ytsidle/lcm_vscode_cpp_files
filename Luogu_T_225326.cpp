#include <bits/stdc++.h>
using namespace std;
//树的直径
//链式前向星
#define int long long 
struct Edge {
    int to,p, next; 
}edge[100005];
int n, pre[50005], cnt = 0;

void add(int u, int v, int w) {
    edge[++cnt] = {v, w, pre[u]};
    pre[u] = cnt;
}

// BFS函数：返回{最远距离, 最远节点}
pair<int, int> bfs(int start) {
    vector<int> depth(n + 1, -1);
    queue<int> q;
    q.push(start);
    depth[start] = 0;
    int max_dist = 0, far_node = start;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = pre[u]; i; i = edge[i].next) {
            int v = edge[i].to;
            if (depth[v] == -1) {
                depth[v] = depth[u] + edge[i].p;
                if (depth[v] > max_dist) {
                    max_dist = depth[v];
                    far_node = v;
                }
                q.push(v);
            }
        }
    }
    return {max_dist, far_node};
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }

    // 第一次BFS找任意端点
    auto [d1, u] = bfs(1);
    // 第二次BFS找直径另一端点
    auto [d2, v] = bfs(u);

    cout << d2 << endl;
    return 0;
}