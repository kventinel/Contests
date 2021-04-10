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

bool cmp(string a, string b) {
    if (a.size() != b.size()) {
        return a.size() > b.size();
    }
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; ++t) {
        int n;
        cin >> n;
        vector<string> v(n);
        for (string &i : v) {
            cin >> i;
        }
        int cnt = 0;
        string first = v[0];
        for (int i = 1; i < n; ++i) {
            if (cmp(v[i], first)) {
                first = v[i];
            } else {
                string a = v[i];
                string b = v[i];
                while (!cmp(a, first)) {
                    a = a + '9';
                    b = b + '0';
                    cnt += 1;
                }
                if (cmp(b, first)) {
                    first = b;
                } else {
                    for (int j = 0; j < first.size(); ++j) {
                        int pos = first.size() - j - 1;
                        if (first[pos] == '9') {
                            first[pos] = '0';
                        } else {
                            first[pos] += 1;
                            break;
                        }
                    }
                }
            }
        }
        cout << "Case #" << t << ": " << cnt << endl;
    }
    return 0;
}
