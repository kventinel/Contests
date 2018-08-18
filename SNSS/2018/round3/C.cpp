#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    vector<string> ans;
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            if (i == j) {
                continue;
            }
            int a = s[i] - '0';
            int b = s[j] - '0';
            if (a - b > 2) {
                continue;
            }
            if (b == 9) {
                continue;
            }
            if (a == 0) {
                continue;
            }
            if (a == 9 && b == 8 && i == 15 && j == 0) {
                bool ok = true;
                for (int z = 0; z < 16; ++z) {
                    if (z == i) {
                        continue;
                    }
                    if (z == j) {
                        continue;
                    }
                    if (s[z] == '9') {
                        continue;
                    }
                    ok = false;
                    break;
                }
                if (ok) {
                    string temp = s;
                    temp[j] = '9';
                    ans.push_back(temp);
                }
            }
            if (b == 0 && a == 1 && i == 15 && j == 0) {
                bool ok = true;
                for (int z = 0; z < 16; ++z) {
                    if (z == i) {
                        continue;
                    }
                    if (z == j) {
                        continue;
                    }
                    if (s[z] == '0') {
                        continue;
                    }
                    ok = false;
                    break;
                }
                if (ok) {
                    string temp = s;
                    temp[i] = '0';
                    ans.push_back(temp);
                }
            }
            bool ok = true;
            --a;
            ++b;
            if (a > b) {
                continue;
            }
            if (a == b && i < j) {
                continue;
            }
            for (int z = 0; z < 16; ++z) {
                if (z == i) {
                    continue;
                }
                if (z == j) {
                    continue;
                }
                if (s[z] - '0' < a) {
                    ok = false;
                    break;
                }
                if (s[z] - '0' == a && z < j) {
                    ok = false;
                    break;
                }
                if (s[z] - '0' > b) {
                    ok = false;
                    break;
                }
                if (s[z] - '0' == b && z > i) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                string temp = s;
                temp[i] = '0' + b;
                temp[j] = '0' + a;
                ans.push_back(temp);
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (auto &t : ans) {
        cout << t << endl;
    }
    if (ans.size() == 0) {
        cout << -1 << endl;
    }
    return 0;
}

