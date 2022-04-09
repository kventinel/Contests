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
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        string s;
        cin >> s;
        vector<pair<char, int> > v;
        v.eb(s[0], 1);
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == v[v.size() - 1].F) {
                ++v[v.size() - 1].S;
            } else {
                v.eb(s[i], 1);
            }
        }
        string res = "";
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < v[i].S; ++j) {
                res += v[i].F;
            }
            if (i + 1 < v.size() && v[i].F < v[i + 1].F) {
                for (int j = 0; j < v[i].S; ++j) {
                    res += v[i].F;
                }
            }
        }
        cout << "Case #" << test << ": " << res << endl;
    }
    return 0;
}
