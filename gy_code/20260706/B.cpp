#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
const int N = 505;
const ll INF = 1e18;
ll d[N][N], d2[N][N];
int a[N][N], c[N][N];
bool vis[N][N], vis2[N][N];
pair<int, int> dp[N][N], dp2[N][N];
int n, q;
signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i != j)
                d[i][j] = INF;
        }
        for (int j = 1; j <= n; j++)
        {
            int mx = 0;

            for (int k = 1; k <= n; k++)
            {
                if (d[i][k] < d[i][mx] && vis[i][k] == 0)
                    mx = k;
            }
            dp[i][j] = {mx, d[i][mx]};
            vis[i][mx] = 1;
            for (int k = 1; k <= n; k++)
            {
                //				cout<<mx<<" "<<k<<" : "<<d[i][mx]+a[mx][k]<<"\n";
                d[i][k] = min(d[i][k], d[i][mx] + a[mx][k]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i != j)
                d2[i][j] = INF;
        }
        for (int j = 1; j <= n; j++)
        {
            int mx = 0;

            for (int k = 1; k <= n; k++)
            {
                if (d2[i][k] < d2[i][mx] && vis2[i][k] == 0)
                    mx = k;
            }
            dp2[i][j] = {mx, d2[i][mx]};
            vis2[i][mx] = 1;
            for (int k = 1; k <= n; k++)
            {
                //				cout<<mx<<" "<<k<<" : "<<d[i][mx]+a[mx][k]<<"\n";
                d2[i][k] = min(d2[i][k], d2[i][mx] + a[k][mx]);
            }
        }
    }
    //	for(int i=1;i<=n;i++){
    //		for(int j=1;j<=n;j++)cout<<d[i][j]<<" ";cout<<"\n";
    //	}
    long long rans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            rans += d[i][j] * c[i][j];
    }
    for (int u = 1; u <= n; u++)
    {
        for (int v = 1; v <= n; v++)
        {
            int nd = d[u][v];
            int lim, yid = 0;
            for (int xid = n; xid >= 1; xid--)
            {
                auto [x, xd] = dp[u][xid];
                lim = nd - xd;
                while (dp2[v][yid + 1].second < lim)
                {
                    yid++;
                }
            }
        }
    }
    return 0;
}
