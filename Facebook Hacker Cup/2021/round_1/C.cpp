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

int MOD = 1000 * 1000 * 1000 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    int tests;
    cin>> tests;
    for (int test = 1; test <= tests; ++ test) {
        int n;
        cin >> n;
        vector<vector<pii>> edges(n);
        vector<int> parent(n, -1);
        vector<int> parent_idx(n);
        stack<int> s;
        stack<int> ss;
        vector<ll> sums(n);
        vector<vector<int>> costs(n, vector<int>(20));
        vector<vector<int>> order(n);
        vector<vector<ll>> son_sum(n);
        vector<vector<int>> son_cost(n);
        vector<vector<ll>> pre_sum(n);
        vector<vector<ll>> suf_sum(n);
        for (int i = 1; i < n; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            --a;
            --b;
            edges[a].eb(b, c);
            edges[b].eb(a, c);
        }
        parent[0] = -2;
        s.push(0);
        while (!s.empty()) {
            int a = s.top();
            s.pop();
            ss.push(a);
            son_cost[a].resize(60 * edges[a].size());
            son_sum[a].resize(edges[a].size());
            pre_sum[a].resize(edges[a].size());
            for (pii b : edges[a]) {
                if (parent[b.F] == -1) {
                    s.push(b.F);
                    parent[b.F] = a;
                }
            }
        }
        while (!ss.empty()) {
            int a = ss.top();
            ss.pop();
            for (pii b : edges[a]) {
                if (b.F == parent[a]) {
                    continue;
                }
                int idx = order[a].size();
                parent_idx[b.F] = idx;
                order[a].pb(b.F);
                son_sum[a][idx] = sums[b.F];
                pre_sum[a][idx] = sums[a];
                for (int i = 0; i < 20; ++i) {
                    son_cost[a][idx * 60 + i + 20] = costs[a][i];
                }
                for (int i = 0; i < b.S; ++i) {
                    son_cost[a][idx * 60 + i] = costs[b.F][i] + 1;
                    son_sum[a][idx] += son_cost[a][idx * 60 + i];
                    sums[a] += costs[a][i] * (ll) son_cost[a][idx * 60 + i];
                    costs[a][i] += son_cost[a][idx * 60 + i];
                }
                sums[a] += son_sum[a][idx];
            }
        }
        s.push(0);
        while (!s.empty()) {
            int a = s.top();
            s.pop();
            ll sum = 0;
            vector<int> tcost(20);
            suf_sum[a].resize(order[a].size(), 0);
            for (int idx = order[a].size() - 1; idx >= 0; --idx) {
                suf_sum[a][idx] = sum;
                for (int i = 0; i < 20; ++i) {
                    son_cost[a][idx * 60 + i + 40] = tcost[i];
                }
                sum += son_sum[a][idx];
                for (int i = 0; i < 20; ++i) {
                    if (son_cost[a][idx * 60 + i] == 0) {
                        break;
                    }
                    sum += tcost[i] * (ll) son_cost[a][idx * 60 + i];
                    tcost[i] += son_cost[a][idx * 60 + i];
                }
            }
            if (parent[a] != -2) {
                int idx = order[a].size() - 1;
                pre_sum[a][idx] = sums[a];
                for (int i = 0; i < 20; ++i) {
                    son_cost[a][idx * 60 + i + 20] = costs[a][i];
                }
            }
            for (const pii& b : edges[a]) {
                if (parent[b.F] != a) {
                    continue;
                }
                s.push(b.F);
                int idx = parent_idx[b.F];
                int idx2 = order[b.F].size();
                ll sum = pre_sum[a][idx] + suf_sum[a][idx];
                for (int i = 0; i < 20; ++i) {
                    ll add = son_cost[a][idx * 60 + i + 20] * (ll) son_cost[a][idx * 60 + i + 40];
                    if (add == 0) {
                        break;
                    }
                    sum += add;
                }
                for (int i = 0; i < b.S; ++i) {
                    son_cost[b.F][idx2 * 60 + i] += son_cost[a][idx * 60 + i + 20] + son_cost[a][idx * 60 + i + 40] + 1;
                    sum += son_cost[b.F][idx2 * 60 + i];
                }
                son_sum[b.F][idx2] = sum;
                order[b.F].pb(a);
            }
        }
        ll res = 1;
        for (int a = 0; a < n; ++a) {
            for (const pii& b : edges[a]) {
                if (b.F == parent[a]) {
                    continue;
                }
                int idx = parent_idx[b.F];
                ll cur_sum = sums[b.F];
                cur_sum += pre_sum[a][idx] + suf_sum[a][idx];
                for (int i = 0; i < 20; ++i) {
                    ll add = son_cost[a][idx * 60 + i + 20] * (ll) son_cost[a][idx * 60 + i + 40];
                    if (add == 0) {
                        break;
                    }
                    cur_sum += add;
                }
                cur_sum %= MOD;
                res *= cur_sum;
                res %= MOD;
            }
        }
        cout << "Case #" << test << ": " << res << endl;
    }
    return 0;
}
