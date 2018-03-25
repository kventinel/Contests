#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int n;
    cin >> n >> s;
    bool ok = false;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
            if (i == 0 || i + 1 == n) {
                ok = true;
            } else if (s[i - 1] == s[i + 1] || s[i - 1] == '?' || s[i + 1] == '?') {
                ok = true;
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        if (s[i] != '?' && s[i] == s[i - 1]) {
            ok = false;
        }
    }
    if (ok) {
        cout << Yesn;
    } else {
        cout << Non;
    }
}
