#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define F first
#define S second
#define pb push_back
#define eb emplace_back

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    ios_base::sync_with_stdio(false);
    random_device rd;
    mt19937 gen(rd());
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int n, k, r, c;
        cin >> n >> k >> r >> c;
        int m = n - 1;
        vector<int> v(n);
        vector<int> w(n);
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            v[i] = i;
            w[i] = i;
        }
        swap(v[r - 1], v[m]);
        w[m] = r - 1;
        p[r - 1] = c;
        while (k > 0 && m > 0) {
            --k;
            int a = uniform_int_distribution<>(1, 2)(gen);
            if (a == 1) {
                cout << "W" << endl;
            } else {
                int b = uniform_int_distribution<>(1, m)(gen);
                cout << "T " << v[b - 1] + 1 << endl;
            }
            cout.flush();
            cin >> r >> c;
            if (p[r - 1] == 0) {
                --m;
                w[v[m]] = w[r - 1];
                swap(v[w[r - 1]], v[m]);
                p[r - 1] = c;
            }
        }
        ll s = 0;
        for (int i = 0; i < n; ++i) {
            s += p[i];
        }
        cout << "E " << s * (n - m) / n / 2 << endl;
    }
    return 0;
}
