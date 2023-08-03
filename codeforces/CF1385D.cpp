#include <bits/stdc++.h>
using namespace std;

int t, n;
string s;

int dfs(int l, int r, char c) {
    if (l+1==r) {
        return s[l]!=c;
    }
    int m = (l+r)/2;
    int x=0 , y=0;
    for (int i=l; i<m; ++i)
        x += (s[i]!=c);
    x += dfs(m, r, c+1);
    y += dfs(l, m, c+1);
    for (int i=m; i<r; ++i)
        y += (s[i]!=c);
    return min(x, y);
}

void solve() {
    cin >> t;
    while (t--) {
        cin >> n >> s;
        cout << dfs(0, n, 'a') << endl;
    }
}

int main() {
    solve();
    return 0;
}
