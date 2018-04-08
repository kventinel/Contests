#include <bits/stdc++.h>

using namespace std;

using ld = long double;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v;
    while (n > 0) {
        v.push_back(n);
        n /= 2;
    }
    vector<int> w(v.size() + 1);
    for (int i = v.size() - 1; i >= 0; --i) {
        int k = 2;
        for (int j = i + 1; j < w.size(); ++j) {
            int u = 0;
            if (v[i] % k > k / 2) {
                u = 1;
            }
            w[i] = max(w[i], w[j] + u);
            k *= 2;
        }
    }
    cout << w[0] << endl;
    return 0;
}
