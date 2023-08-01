#include <bits/stdc++.h>
using namespace std;

int t, n, a[200005];

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; ++i)
            cin >> a[i];
        long long ori=0, ans=0;
        for (int i=0; i<n; i+=2)
            ori += a[i];
        ans = ori;
        for (int s=0; s<=1; ++s) {
            long long cur=0, res=0;
            for (int i=1; i+s<n; i+=2) {
                cur = max((long long) 0, cur+a[i]-(s?a[i+1]:a[i-1]));
                res = max(res, cur);
            }
            ans = max(ans, ori+res);
        }
        cout << ans << endl;
    }
}

int main() {
    solve();
    return 0;
}
