#include <bits/stdc++.h>
#define int long long
using namespace std;
int m, T, rt, dfn[1005], low[1005], ti, cut[1005], vccnt, ins[1005];
vector<int> g[1005], st, vcc[1005];
void tarjan(int u)
{
    dfn[u] = low[u] = ++ti;
    st.push_back(u);
    if (u == rt && g[u].size() == 0)
    {
        vccnt++;
        vcc[vccnt].push_back(u);
        ins[u] = 0;
        st.pop_back();
        return;
    }
    int ch = 0;
    for (auto v : g[u])
    {
        if (!dfn[v])
        {
            ch++;
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u])
            {
                if (u != rt || ch >= 2)
                {
                    cut[u] = 1;
                }
                vccnt++;
                int y = st.back();
                while (u != y)
                {
                    vcc[vccnt].push_back(y);
                    ins[y] = 0;
                    st.pop_back();
                    y = st.back();
                }
                vcc[vccnt].push_back(u);
            }
        }
        else
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> m)
    {
        T++;
        if (m == 0)
        {
            break;
        }
        cout << "Case " << T << ": ";
        for (int i = 0; i <= 1000; i++)
        {
            g[i].clear();
            dfn[i] = 0;
            low[i] = 0;
            cut[i] = 0;
            ins[i] = 0;
            vcc[i].clear();
            vccnt = -0;
        }
        st.clear();
        ti = 0;
        int n = 0;
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            n = max({n, u, v});
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!dfn[i])
            {
                rt = i;
                tarjan(i);
            }
        }
        long long ans = 0, ans2 = 1;
        for (int i = 1; i <= vccnt; i++)
        {
            int cutcnt = 0;
            for (auto u : vcc[i])
            {
                if (cut[u])
                {
                    cutcnt++;
                }
            }
            if (cutcnt == 0)
            {
                ans += 2;
                ans2 *= ((long long)vcc[i].size() * (vcc[i].size() - 1)) / 2;
            }
            else if (cutcnt == 1)
            {
                ans++;
                ans2 *= vcc[i].size() - 1;
            }
        }
        cout << ans << " " << ans2 << "\n";
    }

    return 0;
}