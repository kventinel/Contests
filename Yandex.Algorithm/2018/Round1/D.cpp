#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

vector<int> z_function (string s) {
    int n = (int) s.length();
    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}

bool func(const string &mask, string& s, vector<int> &z, vector<int> &rev, int left, int right) {
    if (right != s.size()) {
        int i = right - 1;
        while (i >= left) {
            if (i + z[i] >= right) {
                right = i;
            }
            --i;
        }
    }
    if (left != 0) {
        int i = left;
        while (i < right) {
            if (i - rev[s.size() - i - 1] + 1 <= left) {
                left = i + 1;
            }
            ++i;
        }
    }
    if (left >= right) {
        return true;
    }
    if (left == 0 || right == s.size()) {
        return false;
    }
    string t = ;
    for (int i = left; i < right; ++i) {
        t += s[i];
    }
    auto tz = z_function(t + '$' + mask);
    for (int i = t.size() + 1; i < tz.size(); ++i) {
        if (tz[i] == right - left) {
            return true;
        }
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    set<string> v;
    for (int i = 0; i < s.size(); ++i) {
        string temp = ;
        for (int j = i; j < s.size(); ++j) {
            temp += s[j];
            v.insert(temp);
        }
    }
    string s2(s);
    reverse(s2.begin(), s2.end());
    for (const string &t : v) {
        auto z = z_function(t + '$' + s);
        z.erase(z.begin(), z.begin() + t.size() + 1);
        string t2(t);
        reverse(t2.begin(), t2.end());
        auto revz = z_function(t2 + '$' + s2);
        revz.erase(revz.begin(), revz.begin() + t.size() + 1);
        bool ok = true;
        int left = 0;
        int i = 0;
        while (i < s.size()) {
            if (z[i] == t.size()) {
                if (i != left) {
                    ok &= func(t, s, z, revz, left, i);
                }
                i += z[i];
                left = i;
            } else {
                ++i;
            }
        }
        if (left < s.size()) {
            ok &= func(t, s, z, revz, left, i);
        }
        if (ok) {
            cout << t << endl;
        }
    }
}
