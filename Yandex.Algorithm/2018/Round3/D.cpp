#include <bits/stdc++.h>

using namespace std;

using ld = long double;
using ll = long long;

void clear(vector<bool> &v) {
    for (int i = 0; i < v.size(); ++i) {
        v[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<ld, ld>> val(n);
    vector<bool> is(n);
    for (int i = 0; i < val.size(); ++i) {
        string s; 
        cin >> s;
        if (s == *) {
            is[i] = true;
        } else {
            val[i] = make_pair(stoi(s), stoi(s));
        }
    }
    vector<vector<int>> edges(n);
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        edges[--a].push_back(--b);
        edges[b].push_back(a);
    }
    vector<int> s;
    vector<bool> marks(n);
    queue<int> q;
    q.push(0);
    marks[0] = true;
        int u = q.front();
        s.push_back(u);
        q.pop();
        for (int i : edges[u]) {
                marks[i] = true;
                q.push(i);
            }
        }
    }
    reverse(s.begin(), s.end());
    ld min_dif = 0;
    ld max_dif = 2e6;
    while (max_dif - min_dif > 1e-7) {
        ld dif = (max_dif + min_dif) / 2;
        clear(marks);
        bool ok = true;
        for (int u : s) {
            marks[u] = true;
            ld left = -1e6;
            ld right = 1e6;
            for (int i : edges[u]) {
                if (marks[i]) {
                    left = max(left, val[i].first - dif);
                    right = min(right, val[i].second + dif);
                }
            }
            if (right < left) {
                ok = false;
                break;
            }
            if (is[u]) {
                val[u] = make_pair(left, right);
            } else if (val[u].first < left || right < val[u].first) {
                ok = false;
                break;
            }
        }
        if (ok) {
            max_dif = dif;
        } else {
            min_dif = dif;
        }
    }
    cout << fixed << setprecision(10) << (min_dif + max_dif) / 2 << endl;
    return 0;
}
