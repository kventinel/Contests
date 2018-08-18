#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void
emplace(const vector<string> &v, vector<vector<int>> &w, deque<pair<int, int>> &q, int i, int j, int k)
{
    if (v[i][j] == '.') {
        w[i][j] = k + 1;
        q.emplace_back(i, j);
    } else {
        w[i][j] = k;
        q.emplace_front(i, j);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (string &a : v) {
        cin >> a;
    }
    deque<pair<int, int>> q;
    vector<vector<int>> w(n, vector<int>(m, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] == 'S') {
                q.emplace_back(i, j);
                w[i][j] = 0;
            } else if (v[i][j] == 'C') {
                for (int k = i - 1; k >= 0; --k) {
                    if (v[k][j] == 'W') {
                        break;
                    }
                    if (v[k][j] == '.') {
                        w[k][j] = -2;
                    }
                }
                for (int k = i + 1; k < n; ++k) {
                    if (v[k][j] == 'W') {
                        break;
                    }
                    if (v[k][j] == '.') {
                        w[k][j] = -2;
                    }
                }
                for (int k = j - 1; k >= 0; --k) {
                    if (v[i][k] == 'W') {
                        break;
                    }
                    if (v[i][k] == '.') {
                        w[i][k] = -2;
                    }
                }
                for (int k = j + 1; k < m; ++k) {
                    if (v[i][k] == 'W') {
                        break;
                    }
                    if (v[i][k] == '.') {
                        w[i][k] = -2;
                    }
                }
            } else if (v[i][j] == 'W') {
                w[i][j] = -2;
            }
        }
    }
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop_front();
        if (v[i][j] == 'L') {
            if (w[i][j - 1] == -1) {
                emplace(v, w, q, i, j - 1, w[i][j]);
            }
        } else if (v[i][j] == 'R') {
            if (w[i][j + 1] == -1) {
                emplace(v, w, q, i, j + 1, w[i][j]);
            }
        } else if (v[i][j] == 'U') {
            if (w[i - 1][j] == -1) {
                emplace(v, w, q, i - 1, j, w[i][j]);
            }
            }
        else if (v[i][j] == 'D') {
            if (w[i + 1][j] == -1) {
                emplace(v, w, q, i + 1, j, w[i][j]);
                }
        } else {
            if (w[i - 1][j] == -1) {
                emplace(v, w, q, i - 1, j, w[i][j]);
            }
            if (w[i + 1][j] == -1) {
                emplace(v, w, q, i + 1, j, w[i][j]);
            }
            if (w[i][j - 1] == -1) {
                emplace(v, w, q, i, j - 1, w[i][j]);
            }
            if (w[i][j + 1] == -1) {
                emplace(v, w, q, i, j + 1, w[i][j]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] == '.') {
                cout << max(w[i][j], -1) << endl;
            }
        }
    }
    return 0;
}
