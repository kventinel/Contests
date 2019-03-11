#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int &i : v) {
        cin >> i;
    }
    set<pii> s;
    set<int> t;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        s.emplace(a, b);
        if (b == v[n - 1]) {
            t.insert(a);
        }
    }
    int k = 0;
    for (int i = n - 2; i >= 0; --i) {
        if (t.find(v[i]) != t.end()) {
            t.erase(v[i]);
            ++k;
            continue;
        }
        vector<int> w;
        for (int z : t) {
            w.push_back(z);
        }
        for (int z : w) {
            if (s.find(make_pair(z, v[i])) == s.end()) {
                t.erase(z);
            }
        }
    }
    cout << k << endl;
    return 0;
}