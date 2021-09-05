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

bool is_vowel(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int main() {
    ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        string s;
        cin >> s;
        vector<int> res(26);
        for (char c : s) {
            for (int i = 0; i < 26; ++i) {
                if (c != 'A' + i) {
                    if (is_vowel(c) == is_vowel('A' + i)) {
                        res[i] += 2;
                    } else {
                        ++res[i];
                    }
                }
            }
        }
        int best = INT32_MAX;
        for (int i = 0; i < 26; ++i) {
            best = min(best, res[i]);
        }
        cout << "Case #" << test << ": " << best << endl;
    }
    return 0;
}
