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
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++ test) {
        int n, k;
        cin >> n >> k;
        vector<int> c(n);
        for (int& i : c) {
            cin >> i;
        }
        vector<pii> edges(n - 1);
        for (auto& i : edges) {
            cin >> i.first >> i.second;
            --i.first;
            --i.second;
        }
        stack<int> final;
        stack<int> s;
        s.push(0);
        vector<vector<int>> sons(n);
        while(!s.empty()) {
            int a = s.top();
            s.pop();
            final.push(a);
            for (auto &e : edges) {
                if (a != e.first) {
                    swap(e.first, e.second);
                }
                if (a == e.first && sons[e.second].size() == 0) {
                    sons[a].push_back(e.second);
                    s.push(e.second);
                }
            }
        }
        vector<vector<int>> open(n, vector<int> (k + 1));
        vector<vector<int>> close(n, vector<int> (k + 1));
        while (!final.empty()) {
            int a = final.top();
            final.pop();
            if (sons[a].size() == 0) {
                for (int i = 0; i <= k; ++i) {
                    open[a][i] = c[a];
                }
                for (int i = 1; i <= k; ++i) {
                    close[a][i] = c[a];
                }
            } else {
                vector<int> cur_close(k + 1);
                for (int i : sons[a]) {
                    for (int j = k; j >= 0; --j) {
                        for (int z = k - j; z >= 0; --z) {
                            if (z + j < k) {
                                cur_close[z + j + 1] = max(cur_close[z + j + 1], open[a][j] + open[i][z]);
                            }
                            open[a][z + j] = max(open[a][z + j], open[a][j] + close[i][z]);
                            open[a][z + j] = max(open[a][z + j], close[a][j] + open[i][z]);
                            close[a][z + j] = max(close[a][z + j], close[a][j] + close[i][z]);
                        }
                    }
                    for (int j = 0; j <= k; ++j) {
                        close[a][j] = max(close[a][j], cur_close[j]);
                        open[a][j] = max(open[a][j], close[a][j]);
                    }
                }
                for (int i = 0; i <= k; ++i) {
                    open[a][i] += c[a];
                }
                for (int i = 1; i <= k; ++i) {
                    if (a != 0) {
                        close[a][i] = max(close[a][i], cur_close[i] + c[a]);
                    } else {
                        close[a][i] = cur_close[i] + c[a];
                    }
                    close[a][i] = max(close[a][i], open[a][i - 1]);
                }
            }
        }
        cout << "Case #" << test << ": " << max(close[0][k], c[0]) << endl;
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j <= k; ++j) {
        //         cout << open[i][j] << " ";
        //     }
        //     cout << "---";
        //     for (int j = 0; j <= k; ++j) {
        //         cout << close[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
    return 0;
}
