#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    vector<bool> rows(n, false);
    vector<bool> cols(m, false);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < n; ++i) {
            int last = -1;
            vector<bool> temp_cols(m, false);
            for (int j = 0; j < m; ++j) {
                if (v[i][j] == '#') {
                    temp_cols[j] = true;
                    last = j;
                    if (cols[j]) {
                        cout << Non;
                        return 0;
                    }
                    cols[j] = true;
                }
            }
            if (last != -1) {
                vector<bool> temp_rows(n, false);
                for (int k = 0; k < n; ++k) {
                    if (v[k][last] == '#') {
                        temp_rows[k] = true;
                        if (rows[k]) {
                            cout << Non;
                            return 0;
                        }
                        rows[k] = true;
                    }
                }
                for (int j = 0; j < m; ++j) {
                    for (int k = 0; k < n; ++k) {
                        if (temp_rows[k] && temp_cols[j] && v[k][j] != '#') {
                            cout << Non;
                            return 0;
                        } else if ((temp_rows[k] ^ temp_cols[j]) && v[k][j] == '#') {
                            cout << Non;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << Yesn;
    return 0;
}
