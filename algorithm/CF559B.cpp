#include <bits/stdc++.h>
using namespace std;

string s1, s2;

string dsort(string s, int n) {
    if (n&1)
        return s;
    string t1 = dsort(s.substr(0, n/2), n/2);
    string t2 = dsort(s.substr((n+1)/2, n/2), n/2);
    return (t1<t2)?(t1+t2):(t2+t1);
}

void solve() {
    cin >> s1 >> s2;
    string t1 = dsort(s1, s1.size());
    string t2 = dsort(s2, s2.size());
    cout << ((t1==t2)?"YES":"NO") << endl;
}

int main() {
    solve();
    return 0;
}
