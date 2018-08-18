#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

bool
intersect(int l, int r, int n) {
    if (l <= r) {
        return true;
    }
    if (r + 2 * n < l) {
        return true;
    }
    return false;
}

bool
bin (int n, int m, const string &s)
{
    for (int i = 1; i + 2 * n - 1 < s.size(); ++i) {
        int l = i;
        int r = s.size() - 1;
        int val = 0;
        for (int j = 0; j < n; ++j) {
            val += abs(s[l] - s[r]);
            ++l;
            --r;
        }
        if (val <= m && intersect(l, r, n)) {
            return true;
        }
        while (l < s.size() && r >= 0) {
            val += abs(s[l] - s[r]);
            val -= abs(s[l - n] - s[r + n]);
            ++l;
            --r;
            if (val <= m && intersect(l, r, n)) {
                return true;
            }
        }
    }
    for (int i = 2 * n - 1; i < s.size(); ++i) {
        int l = 0;
        int r = i;
        int val = 0;
        for (int j = 0; j < n; ++j) {
            val += abs(s[l] - s[r]);
            ++l;
            --r;
        }
        if (val <= m && intersect(l, r, n)) {
            return true;
        }
        while (l < s.size() && r >= 0) {
            val += abs(s[l] - s[r]);
            val -= abs(s[l - n] - s[r + n]);
            ++l;
            --r;
            if (val <= m && intersect(l, r, n)) {
                return true;
            }
        }
    }
    return false;
}

void
fun()
{
    int m;
    string s;
    cin >> m >> s;
    int min_len = 0;
    int max_len = s.size();
    while (min_len + 1 < max_len) {
        int mid = (max_len + min_len) / 2;
        if (bin(mid, m, s)) {
            min_len = mid;
        } else {
            max_len = mid;
        }
    }
    cout << min_len << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    while(n--) {
        fun();
    }
    return 0;
}

