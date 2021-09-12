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
        int len;
        string s;
        cin >> len >> s;
        int best = INT32_MAX;
        for (int i = 0; i < 2; ++i) {
            int hand = i;
            int cnt = 0;
            for (char c : s) {
                if (c == 'O' && hand == 0) {
                    hand = 1;
                    ++cnt;
                } else if (c == 'X' && hand == 1) {
                    hand = 0;
                    ++cnt;
                }
            }
            best = min(best, cnt);
        }
        cout << "Case #" << test << ": " << best << endl;
    }
    return 0;
}
