#include <bits/stdc++.h>
using namespace std;

int n, a[5005];

int dfs(int l, int r, int y) {
    int h = INT_MAX;
    for (int i=l; i<r; ++i)
        h = min(h, a[i]);
    int vb = r-l;
    int hb = h-y;
    if (hb==0)
        return 0;
    int tl = -1;
    for (int i=l; i<r; ++i) {
        if (a[i]==h) {
            if (tl!=-1) {
                hb += dfs(tl, i, h);
                tl = -1;
            }
        }
        else if (tl==-1)
            tl = i;
    }
    if (tl!=-1)
        hb += dfs(tl, r, h);
    return min(vb, hb);
}

void solve() {
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    cout << dfs(0, n, 0) << endl;
}

int main() {
    solve();
    return 0;
}