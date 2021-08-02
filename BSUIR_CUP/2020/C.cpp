#include <bits/stdc++.h>

using namespace std;

string check(string s, string t, int a) {
    string ans;
    int n = s.length();
    for (int i = 0, j = 0; i < n || j < n;) {
        if (i == n) {
            ans += t[j];
            ++j;
        } else if (j == n) {
            ans += s[i];
            ++i;
        } else if (s[i] == t[j]) {
            ans += s[i];
            ++i;
            ++j;
        } else if (a == 1) {
            ans += s[i];
            ++i;
            a = -1;
        } else if (a == 2) {
            ans += t[j];
            ++j;
            a = -1;
        } else if (a == -1) {
            if (i < j) {
                ans += s[i];
                ++i;
            } else {
                ans += t[j];
                ++j;
            }
            a = -2;
        } else {
            return "";
        }
    }
    return ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    if (s == t) {
        cout << s + "a" << endl;
        return 0;
    }
    string ans = check(s, t, 1);
    if (ans != "") {
        cout << ans << endl;
        return 0;
    }
    ans = check(s, t, 2);
    if (ans != "") {
        cout << ans << endl;
        return 0;
    }
    cout << "IMPOSSIBLE" << endl;
}
