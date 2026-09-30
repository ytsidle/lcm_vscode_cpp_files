#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
vector<pii> g[3005];
int n, m, v[3005], dp[3005][3005];
int dfs(int u, int fa)
{
    dp[u][0] = 0;
    if(g[u].size()==1){
        dp[u][1] = v[u];
        return 1;
    }
    int sz=1,gg;
    for (auto [v, w] : g[u])
    {

        if (v == fa)
            continue;
        sz+=(gg=dfs(v, u));
        for (int j = sz; j ;j--)
        {
            for (int k = 1; k <= min(j,gg); k++)
            {
                dp[u][j] = max(dp[u][j], dp[u][j - k] - w + dp[v][k]);
            }
        }
    }
    
    return sz;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    // memset(dp,-0x3f,sizeof(dp));
    for(int i=1;i<=n;i++) fill(dp[i],dp[i]+m+4,-1e9);
    for (int i = 1; i <= n - m; i++)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int ta, tc;
            cin >> ta >> tc;
            g[i].emplace_back(ta, tc);
            g[ta].emplace_back(i, tc);
        }
    }
    for (int i = n - m + 1; i <= n; i++)
        cin >> v[i];
    dfs(1, 0);
    for (int i = m; i >= 0; i--)
    {
        if (dp[1][i] >= 0)
        {
            cout << i;
            break;
        }
    }
    return 0;
}