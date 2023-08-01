#include <bits/stdc++.h>
using namespace std;

int t, n, a[100];
int res[100];

void dfs(int l, int r, int c) {
    if (l>=r)
        return;
    int mi, mv;
    mi = -1;
    mv = -1;
    for (int i=l; i<r; ++i) {
        if (a[i]>mv) {
            mi = i;
            mv = a[i];
        }
    }
    res[mi] = c;
    dfs(l, mi, c+1);
    dfs(mi+1, r, c+1);
}

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; ++i) {
            cin >> a[i];
            res[i] = 0;
        }
        dfs(0, n, 0);
        for (int i=0; i<n; ++i)
            cout << res[i] << ' ';
        cout << endl;
    }    
}

int main() {
    solve();
    return 0;
}
