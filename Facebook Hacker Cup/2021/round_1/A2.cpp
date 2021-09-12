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

int MOD = 1000 * 1000 * 1000 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int len;
        string s;
        cin >> len >> s;
        int hand = -1;
        ll j = -1;
        ll res = 0;
        for (int i = 0; i < len; ++i) {
            if (s[i] == 'O') {
                if (hand == 0) {
                    res += (j + 1) * (len - i);
                }
                j = i;
                hand = 1;
            } else if (s[i] == 'X') {
                if (hand == 1) {
                    res += (j + 1) * (len - i);
                }
                j = i;
                hand = 0;
            }
        }
        cout << "Case #" << test << ": " << res % MOD << endl;
    }
    return 0;
}
