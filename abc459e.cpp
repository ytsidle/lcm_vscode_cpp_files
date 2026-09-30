#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 998244353;
const int MAXF = 1000000 + 5; // enough for max D (<=1e6)
ll fact[MAXF], invfact[MAXF];

ll pow_mod(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void precompute_fact(int maxk) {
    fact[0] = 1;
    for (int i = 1; i <= maxk; ++i)
        fact[i] = fact[i-1] * i % MOD;
    invfact[maxk] = pow_mod(fact[maxk], MOD-2);
    for (int i = maxk-1; i >= 0; --i)
        invfact[i] = invfact[i+1] * (i+1) % MOD;
}

// compute C(n, k) mod MOD for possibly large n and small k (k <= 1e6)
ll nCr_large_n(ll n, int k) {
    if (k == 0) return 1;
    ll n_mod = n % MOD;
    ll num = 1;
    for (int i = 0; i < k; ++i) {
        // (n - i) mod MOD
        ll term = (n_mod - i + MOD) % MOD;
        num = num * term % MOD;
    }
    return num * invfact[k] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> children(N+1);
    vector<int> parent(N+1);
    parent[1] = 0;
    for (int i = 2; i <= N; ++i) {
        int p;
        cin >> p;
        parent[i] = p;
        children[p].push_back(i);
    }

    vector<ll> C(N+1);
    for (int i = 1; i <= N; ++i) cin >> C[i];

    vector<int> D(N+1);
    int maxD = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> D[i];
        if (D[i] > maxD) maxD = D[i];
    }

    // precompute factorials up to MAXF-1 (safe since maxD <= 1e6)
    precompute_fact(MAXF-1);

    // topological order from leaves to root
    vector<int> processed_children(N+1, 0);
    for (int i = 1; i <= N; ++i)
        processed_children[i] = children[i].size();

    queue<int> q;
    for (int i = 1; i <= N; ++i)
        if (processed_children[i] == 0)
            q.push(i);

    vector<ll> rem(N+1, 0); // candies left in subtree after satisfying all squirrels in it
    ll ans = 1;
    bool impossible = false;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        ll total_free = C[u];
        for (int v : children[u])
            total_free += rem[v];

        if (total_free < D[u]) {
            impossible = true;
            break;
        }

        ans = ans * nCr_large_n(total_free, D[u]) % MOD;
        rem[u] = total_free - D[u];

        if (u != 1) {
            int p = parent[u];
            if (--processed_children[p] == 0)
                q.push(p);
        }
    }

    if (impossible) cout << "0\n";
    else cout << ans << "\n";

    return 0;
}