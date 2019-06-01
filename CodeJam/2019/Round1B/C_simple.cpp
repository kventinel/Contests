#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int solve(int k, const vector<int> &a, const vector<int> &b) {
    int ans = 0;
    for (int l = 0; l < a.size(); ++l) {
        for (int r = l; r < a.size(); ++r) {
            int c = 0;
            int d = 0;
            for (int i = l; i <= r; ++i) {
                c = max(c, a[i]);
                d = max(d, b[i]);
            }
            if (abs(c - d) <= k) {
                ++ans;
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int m, k;
        cin >> m >> k;
        vector<int> a(m);
        vector<int> b(m);
        for (int &j : a) {
            cin >> j;
        }
        for (int &j : b) {
            cin >> j;
        }
        int ans = solve(k, a, b);
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}