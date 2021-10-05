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
#include <cassert>

#define F first
#define S second
#define pb push_back
#define eb emplace_back

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

class Tree {
public:
    vector<int> v;
    int p;
    int size;
    Tree(int size_) {
        size = size_;
        p = 1;
        while (p < size) {
            p *= 2;
        }
        v.resize(2 * p);
    }

    void update(int pos, int val) {
        pos += p;
        int diff = val - v[pos];
        while (pos > 0) {
            v[pos] += diff;
            pos /= 2;
        }
    }

    int prefix(int val) {
        int pos = 1;
        int sum = 0;
        while (pos < p) {
            if (sum + v[pos * 2] < val) {
                pos = pos * 2 + 1;
                sum += v[pos * 2];
            } else {
                pos = pos * 2;
            }
        }
        sum += v[pos];
        return sum == val ? pos - p : size;
    }

    int suffix(int val) {
        int pos = 1;
        int sum = 0;
        while (pos < p) {
            if (sum + v[pos * 2 + 1] < val) {
                pos = pos * 2;
                sum += v[pos * 2 + 1];
            } else {
                pos = pos * 2 + 1;
            }
        }
        sum += v[pos];
        return sum == val ? pos - p : -1;
    }
};

class MinTree {
public:
    vector<int> v;
    vector<int> add;
    int p;

    MinTree(int size) {
        p = 1;
        while(p < size) {
            p *= 2;
        }
        v.resize(2 * p, INT32_MAX);
        add.resize(2 * p);
    }

    void set(int pos, int val) {
        stack<int> s;
        int n = (pos + p) / 2;
        while (n > 0) {
            s.push(n);
            n /= 2;
        }
        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++ test) {
        int n, m, k, s;
        cin >> n >> m >> k >> s;
        vector<string> v(n);
        for (auto &s : v) {
            cin >> s;
        }
        ll sum_res = 0;
        vector<int> raw_res(n);
        vector<Tree> cars(m, Tree(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (v[i][j] == 'X') {
                    ++raw_res[i];
                    cars[j].update(i, 1);
                }
            }
        }
        for (int z = 0; z < s; ++z) {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            int prefix_old = cars[b].prefix(k);
            int suffix_old = cars[b].suffix(k);
            if (v[a][b] == 'X') {
                --raw_res[a];
                v[a][b] = '.';
                cars[b].update(a, 0);
            } else {
                ++raw_res[a];
                v[a][b] = 'X';
                cars[b].update(a, 1);
            }
            int best_res = raw_res[k - 1];
            int prefix_new = cars[b].prefix(k);
            int suffix_new = cars[b].suffix(k);
            if (prefix_new != prefix_old) {

            }
            if (suffix_new != suffix_old) {

            }
        }
        vector<int> up(m);
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < m; ++j) {
                if (v[i][j] == 'X') {
                    ++up[j];
                }
            }
        }
        for (int i = k; i < n; ++i) {
            int res = i - k + 1;
            for (int j = 0; j < m; ++j) {
                if (v[i][j] == 'X') {
                    ++res;
                    ++up[j];
                } else if (up[j] >= k) {
                    ++res;
                }
            }
            best_res = min(best_res, res);
        }
        int res = n - k + 1;
        for (int j = 0; j < m; ++j) {
            if (up[j] >= k) {
                ++res;
            }
        }
        best_res = min(best_res, res);
        vector<int> down(m);
        for (int i = k - 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (v[i][j] == 'X') {
                    ++down[j];
                }
            }
        }
        for (int i = k - 2; i >= 0; --i) {
            int res = k - i - 1;
            for (int j = 0; j < m; ++j) {
                if (v[i][j] == 'X') {
                    ++res;
                    ++down[j];
                } else if (down[j] >= n - k + 1) {
                    ++res;
                }
            }
            best_res = min(best_res, res);
        }
        res = k;
        for (int j = 0; j < m; ++j) {
            if (down[j] >= n - k + 1) {
                ++res;
            }
        }
        best_res = min(best_res, res);
        cout << "Case #" << test << ": " << best_res << endl;
    }
    return 0;
}
