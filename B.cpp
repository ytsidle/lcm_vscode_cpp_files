#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e9 + 1;
const int M = 1e5 + 10;
int n, a[M], dep[M], m, fa[M], sz[M], sons[M], top[M], rt = 1, in[M];
vector<int> g[M];
struct Seg
{

    struct Node
    {
        int sum, tag;
    } tr[4 * M];

    void up(int x)
    {
        tr[x].sum = tr[x << 1].sum + tr[x << 1 | 1].sum;
    }
    void push_down(int x, int l, int r)
    {
        if (tr[x].tag)
        {
            int tag = tr[x].tag, mid = (l + r) >> 1;
            // tr[x].sum-=(r-l+1)*tr[x].tag;
            tr[x << 1].sum += tag * (mid - l + 1);
            tr[x << 1 | 1].sum += tag * (r - mid);
            tr[x << 1].tag += tag;
            tr[x << 1 | 1].tag += tag;
            tr[x].tag = 0;
        }
    }
    void build(int p, int l, int r)
    {
        if (l == r)
        {
            tr[p].sum = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        up(p);
    }
    void update(int p, int l, int r, int L, int R, int add)
    {
        if (L <= l && r <= R)
        {
            tr[p].tag += add;
            tr[p].sum += (r - l + 1) * add;
            return;
        }
        if (l > R || r < L)
            return;
        push_down(p, l, r);
        int mid = (l + r) >> 1;
        if (L <= mid)
            update(p << 1, l, mid, L, R, add);
        if (R > mid)
            update(p << 1 | 1, mid + 1, r, L, R, add);
        up(p);
    }
    int query(int p, int l, int r, int L, int R)
    {
        if (r < l || R < L)
            return INF;
        if (L <= l && r <= R)
            return tr[p].sum;
        int mid = (l + r) >> 1;
        int ans = 0;
        push_down(p, l, r);
        if (L <= mid)
            ans += query(p << 1, l, mid, L, R);
        if (R > mid)
            ans += query(p << 1 | 1, mid + 1, r, L, R);
        return ans;
    }
} seg;
int ti;
void dfs1(int x)
{
    dep[x] = dep[fa[x]] + 1;
    sz[x] = 1;
    int maxs = -1;
    for (int v : g[x])
    {
        dfs1(v);
        sz[x] += sz[v];
        if (sz[v] > maxs)
        {
            sons[x] = v;
            maxs = sz[v];
        }
    }
}
void dfs2(int u, int t)
{
    top[u] = t;
    in[u] = ++ti;
    if (sons[u] == 0)
        return;
    dfs2(sons[u], t);
    for (int v : g[u])
    {
        if (v == sons[u])
            continue;
        dfs2(v, v);
    }
}
void addp(int u, int v, int val)
{
    // 链加
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        seg.update(1, 1, n, in[top[u]], in[u], val);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v])
        swap(u, v);
    seg.update(1, 1, n, in[v], in[u], val);
}
int queryp(int u, int v)
{
    int ret = 0;
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        ret += seg.query(1, 1, n, in[top[u]], in[u]);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v])
        swap(u, v);
    ret += seg.query(1, 1, n, in[v], in[u]);
    return ret;
}
int find(int x, int y)
{
    while (top[x] != top[y])
    {
        if (fa[top[y]] == x)
            return top[y];
        y = fa[top[y]];
    }
    return sons[x];
}
void addt(int u, int val)
{
    if (u == rt)
    {
        // 全树加
        seg.update(1, 1, n, 1, n, val);
    }
    else if (in[u] <= in[rt] && in[rt] <= in[u] + sz[u] - 1)
    {
        // 在u子树内
        seg.update(1, 1, n, 1, n, val);
        int ss = find(u, rt); // rt祖先中是u儿子的
        seg.update(1, 1, n, in[ss], in[ss] + sz[ss] - 1, -val);
    }
    else
    {
        // 在u子树外
        seg.update(1, 1, n, in[u], in[u] + sz[u] - 1, val);
    }
}
int queryt(int u)
{
    if (u == rt)
    {
        return seg.query(1, 1, n, 1, n);
    }
    else if (in[u] <= in[rt] && in[rt] <= in[u] + sz[u] - 1)
    {

        int ss = find(u, rt); // rt祖先中是u儿子的
        return seg.query(1, 1, n, 1, n) - seg.query(1, 1, n, in[ss], in[ss] + sz[ss] - 1);
    }
    else
    {

        return seg.query(1, 1, n, in[u], in[u] + sz[u] - 1);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++)
    {
        cin >> fa[i];
        g[fa[i]].emplace_back(i);
    }
    dfs1(1);
    dfs2(1, 1);
    for (int i = 1; i <= n; i++)
    {
        seg.update(1, 1, n, in[i], in[i], a[i]);
    }
    int m;
    cin >> m;
    while (m--)
    {
        int op;
        cin >> op;
        int u, v, k;
        ;
        cin >> u;
        if (op == 1)
        {
            rt = u;
        }
        if (op == 2)
        {
            cin >> v >> k;
            addp(u, v, k);
        }
        if (op == 3)
        {
            cin >> k;
            addt(u, k);
        }
        if (op == 4)
        {
            cin >> v;
            cout << queryp(u, v) << "\n";
        }
        if (op == 5)
        {
            cout << queryt(u) << "\n";
        }
    }
    return 0;
}