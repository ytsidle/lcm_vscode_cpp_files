#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], dfn[N], low[N], ins[N], ti, ecccnt, bel[N], dep[N], st[N][20], tag[N], is[N];
long long ans, sum[N];
vector<int> g[N];
vector<int> stk, g2[N];
// 割边 缩点
void tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++ti;
    ins[u] = 1;
    stk.push_back(u);
    for (auto v : g[u])
    {
        if (v == fa)
            continue;
        if (!dfn[v])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if (ins[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        ecccnt++;
        int y;
        do
        {
            y = stk.back();
            stk.pop_back();
            ins[y] = 0;
            bel[y] = ecccnt;
            sum[ecccnt] += 1ll * a[y];
        } while (u != y);
    }
}
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    st[u][0] = fa;
    for (int i = 1; i <= 19; i++)
    {
        st[u][i] = st[st[u][i - 1]][i - 1];
    }
    for (auto v : g2[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
    }
}
int lca(int x, int y)
{
    if (dep[x] < dep[y])
        swap(x, y);
    int k = dep[x] - dep[y];
    for (int i = 0; (1 << i) <= k; i++)
    {
        if (k & (1 << i))
        {
            x = st[x][i];
        }
    }
    if (x == y)
        return x;
    for (int i = 19; i >= 0; i--)
    {
        if (st[x][i] != st[y][i])
        {
            x = st[x][i];
            y = st[y][i];
        }
    }
    return st[x][0];
}
void pusd(int u, int fa)
{
    // cout << u << " " << tag[u] << endl;
    for (auto v : g2[u])
    {
        if (v == fa)
            continue;
        pusd(v, u);
        tag[u] += tag[v];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    tarjan(1, -1);
    int q;
    cin >> q;
    for (int i = 1; i <= n; i++)
    {
        for (auto v : g[i])
        {
            if (bel[i] != bel[v])
            {
                // 建缩点图
                // cout << id << " " << bel[i] << " " << bel[v] << " add\n";
                g2[bel[i]].push_back(bel[v]);
            }
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     // 去重
    //     sort(g2[i].begin(), g2[i].end());
    //     g2[i].erase(unique(g2[i].begin(), g2[i].end()), g2[i].end());
    // }
    dfs(1, -1);
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        x = bel[x];
        y = bel[y];
        int lc = lca(x, y);
        tag[x]++;
        tag[y]++;
        tag[lc]--;
        tag[st[lc][0]]--;
    }
    pusd(1, -1);
    for (int i = 1; i <= ecccnt; i++)
    {
        if (tag[i] > 0)
            ans += sum[i];
    }

    cout << ans << endl;
    return 0;
}