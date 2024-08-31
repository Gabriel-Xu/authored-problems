#include <bits/stdc++.h>

using namespace std;

#define int ll

using ll = long long;

const int mxn = 2e5+5;
ll h;
vector<ll> c, dp;
vector<int> adj[mxn];
vector<bool> vis;

void dfs(int x) {
    vis[x] = true;
    
    ll sm = 0;
    for (auto y : adj[x]) {
        if (!vis[y]) {
            dfs(y);
            sm += dp[y];
        }
    }
    
    dp[x] = h * c[x];
    if (sm > 0) dp[x] = min(dp[x], sm);
}

signed main() {
    int n; cin >> n >> h;
    c.resize(n);
    dp.resize(n);
    vis.resize(n, false);
    for (int i = 0; i < n; i++) cin >> c[i];
    
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(0);
    cout << dp[0] << endl;
    
    
}
