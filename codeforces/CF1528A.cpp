#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

int t, n, l[100005], r[100005], u, v;

pll dfs(vector<vector<int>>& adj, int u, int p) {
    pll au={0, 0}, av={0, 0};
    for (int v : adj[u]) {
        if (v!=p) {
            av = dfs(adj, v, u);
            au.first += max(av.first+abs(l[v]-l[u]), av.second+abs(r[v]-l[u]));
            au.second += max(av.first+abs(l[v]-r[u]), av.second+abs(r[v]-r[u]));
        }
    }
    return au;
}

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=1; i<=n; ++i)
            cin >> l[i] >> r[i];
        vector<vector<int>> adj(n+5);
        for (int i=1; i<=n-1; ++i) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        pll ans = dfs(adj, 1, 0);
        cout << max(ans.first, ans.second) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    solve();
    return 0;
}