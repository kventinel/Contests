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
        int n;
        cin >> n;
        std::unordered_map<string, int> changes;
        for (int i = 0; i < n; ++i) {
            string a;
            cin >> a;
            changes[a] = 1;
        }
        while(true) {
            int nn = 0;
            auto it1 = changes.begin();
            while (it1 != changes.end()) {
                auto it2 = changes.begin();
                while (it2 != changes.end()) {
                    if (it1->first[1] == it2->first[0] && it1->first[0] != it2->first[1]) {
                        string a = "AA";
                        a[0] = it1->first[0];
                        a[1] = it2->first[1];
                        if (changes[a] == 0 || changes[a] > it1->second + it2->second) {
                            changes[a] = it1->second + it2->second;
                            ++nn;
                        }
                    }
                    ++it2;
                }
                ++it1;
            }
            if (nn == 0) {
                break;
            }
        }
        vector<int> res(26);
        std::vector<bool> can(26, true);
        for (char c : s) {
            for (int i = 0; i < 26; ++i) {
                if (c != 'A' + i) {
                    bool cn = false;
                    for (auto a : changes) {
                        if (a.first[0] == c && a.first[1] == 'A' + i) {
                            res[i] += a.second;
                            cn = true;
                        }
                    }
                    can[i] = cn && can[i];
                }
            }
        }
        int best = INT32_MAX;
        for (int i = 0; i < 26; ++i) {
            if (can[i]) {
                best = min(best, res[i]);
            }
        }
        if (best == INT32_MAX) {
            best = -1;
        }
        cout << "Case #" << test << ": " << best << endl;
    }
    return 0;
}
