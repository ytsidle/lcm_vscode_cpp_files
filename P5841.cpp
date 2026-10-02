#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 5;
string s[N];
int n, q, sz[N], rsz[N];
struct Tree
{
    int dep[N], fa[N];
    vector<int> g[N];
    void dfs(int x)
    {
        for (int v : g[x])
        {
            fa[v] = x;
            dep[v] = dep[x] + 1;
            dfs(v);
        }
    }
    void add(int u, int v)
    {
        g[u].push_back(v);
        // cerr << u << "->" << v << "\n";
    }
    void out()
    {
        for (int i = 1; i <= 10; i++)
        {
            cerr << i << " : ";
            for (int v : g[i])
                cerr << v << " ";
            cerr << "\n";
        }
        cerr << "----------------------\n";
    }
} ta;
struct Uni
{
    int f[N];
    void _init_(int sz)
    {
        for (int i = 0; i <= sz; i++)
            f[i] = i;
    }
    int find(int x)
    {
        return f[x] == x ? x : f[x] = find(f[x]);
    }
    void add(int u, int v)
    {
        u = find(u), v = find(v);
        f[u] = v;
    }
} uni;
int ch[N][27], tot = 1, dep[N];
void insert(string s)
{
    int u = 1;
    dep[u] = 0;
    for (int i = 0; i <= (int)s.size(); ++i)
    {
        int c = i == (int)s.size() ? 26 : s[i] - 'a';
        if (!ch[u][c])
        {
            ch[u][c] = ++tot;
            ++sz[u];
        }
        dep[ch[u][c]] = dep[u] + 1;
        u = ch[u][c];
    }
}
int deg[N];
using ll = long long;
ll ans = 0;
void dfs(int x, int l)
{
    int keep = (x == 1 || sz[x] != 1);
    if (keep)
    {
        if (l)
        {
            ta.add(l, x);
        }
        l = x;
    }

    ans += 1ll * (dep[x] * max(0, sz[x] - 1)) * dep[x];
    for (int i = 0; i <= 26; i++)
    {
        if (ch[x][i])
            dfs(ch[x][i], l);
    }
}
const int M = 1e5 + 5;
struct Task
{
    int u, v;
} tasks[M];
vector<int> ansT;
int find(string s)
{
    int p = 1;
    for (int i = 0; i < s.size(); i++)
    {
        p = ch[p][s[i] - 'a'];
    }
    return ch[p][26];
}
int nxt[N], suf[N];
struct Node
{
    int f = 0, l = 0;
} nodes[N];
int fi[N];
int lca(Task task)
{
    int u = task.u, v = task.v;
    // cerr<<"----\n";
    // cerr<<u<<" "<<v<<"\n";
    // u,v  => u:l v:f
    while (u != v)
    {
        if (ta.dep[u] < ta.dep[v])
        {
            v = ta.fa[v];
        }
        else
        {
            u = ta.fa[u];
        }
    }
    return u;
}
bool check2(Task task, int x)
{
    int u = task.u, v = task.v;
    // u,v  => u:l v:f
    int us = -1, vs = -1;
    // cerr<<"----\n";
    while (u != v)
    {
        // cerr<<u<<" "<<v<<" "<<x<<"\n";
        if (ta.dep[u] < ta.dep[v])
        {
            if (ta.fa[v] != x)
            {
                if ((nodes[ta.fa[v]].f != v && nodes[ta.fa[v]].f != 0) || suf[ta.fa[v]])
                    return 0;
            }

            else
                vs = v;
            v = ta.fa[v];
        }
        else
        {
            if (ta.fa[u] != x)
            {
                if ((nodes[ta.fa[u]].l != v && nodes[ta.fa[u]].l != 0) || nxt[ta.fa[u]])
                    return 0;
            }

            else
                us = u;
            u = ta.fa[u];
        }
    }
    // cerr<<us<<" deg "<<vs<<"\n---\n";
    if ((nxt[us] == vs || nxt[us] == 0) && (suf[vs] == us || suf[vs] == 0))
        return 1;
    else
        return 0;
}
void Modify(Task task, int x)
{
    int u = task.u, v = task.v;
    // u,v  => u:l v:f
    int us = 0, vs = 0;
    while (u != v)
    {
        if (ta.dep[u] < ta.dep[v])
        {
            if (ta.fa[v] != x)
                nodes[ta.fa[v]].f = v;
            else
                vs = v;
            v = ta.fa[v];
        }
        else
        {
            if (ta.fa[u] != x)
                nodes[ta.fa[u]].l = u;
            else
                us = u;
            u = ta.fa[u];
        }
    }
    nxt[us] = vs;
    suf[vs] = us;
    uni.add(us, vs);
}
map<pair<int, int>, bool> mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        insert(s[i]);
        //        cerr<<s[i]<<"\n";
    }
    for (int i = 1; i <= n; i++)
    {
        fi[i] = find(s[i]);
    }
    uni._init_(tot);
    for (int i = 1; i <= q; i++)
    {
        cin >> tasks[i].u >> tasks[i].v;
        tasks[i].u = fi[tasks[i].u];
        tasks[i].v = fi[tasks[i].v];
    }
    ta.fa[1] = 0;
    dfs(1, 0);
    ta.dfs(1);
    // ta.out();
    for (int i = q; i >= 1; i--)
    {
        int lcs = lca(tasks[i]);
        // cerr<<lcs<<"\n";
        bool x = check2(tasks[i], lcs);
        // cerr<<i<<" "<<x<<"\n";
        auto it = mp.find({tasks[i].u, tasks[i].v});
        if (it != mp.end())
        {
            if (it->second)
            {
                ansT.push_back(i);
            }
            continue;
        }
        mp[{tasks[i].u, tasks[i].v}] = x;

        if (x)
        {
            Modify(tasks[i], lcs);
            ansT.push_back(i);
        }
    }
    // for(int i=1;i<=10;i++){
    // cerr<<i<<" n f:"<<nxt[i]<<" "<<suf[i]<<'\n';
    // }
    cout << ans << "\n";
    cout << ansT.size() << " ";
    for (auto v = ansT.rbegin(); v != ansT.rend(); v++)
        cout << *v << " ";
    cout << "\n";
    for (int i = 1; i <= n; i++)
        cout << i << " ";
    return 0;
}
