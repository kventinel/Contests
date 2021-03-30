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
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; ++t) {
        int x, y;
        string s;
        cin >> x >> y >> s;
        char first = '?';
        for (char c : s) {
            if (c == '?') {
                continue;
            } else {
                first = c;
                break;
            }
        }
        if (first == '?') {
            first = 'C';
        }
        int cost = 0;
        for (char &c : s) {
            if (c == '?') {
                c = first;
            } else if (c != first) {
                if (first == 'C') {
                    cost += x;
                } else {
                    cost += y;
                }
                first = c;
            }
        }
        cout << "Case #" << t << ": " << cost << endl;
    }
    return 0;
}
