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

int main() {
    ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++ test) {
        int n;
        cin >> n;
        vector<vector<int> > edges(n);
        unordered_map<int, vector<int>> freq;
        for (int i = 1; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            edges[a].pb(b);
            edges[b].pb(a);
        }
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            freq[a].pb(i);
        }
        vector<int> deep(n, -1);
        vector<int> parent(n, -1);
        vector<int> portal(n, -1);
        deep[0] = 0;
        stack<int> s;
        s.push(0);
        while (!s.empty()) {
            int a = s.top();
            s.pop();
            for (int i : edges[a]) {
                if (deep[i] == -1) {
                    s.push(i);
                    deep[i] = deep[a] + 1;
                    parent[i] = a;
                }
            }
        }
        auto it = freq.begin();
        while (it != freq.end()) {
            if (it->S.size() != 1) {
                set<pii> nodes;
                unordered_set<int> road;
                for (int i : it->S) {
                    nodes.emplace(-deep[i], i);
                    road.insert(i);
                }
                while (nodes.size() != 1) {
                    int i = nodes.begin()->S;
                    // cout << deep[i] << " " << i << endl;
                    // if (i == 0) {
                    //     for (int j : portal) {}
                    //     for (auto &j : nodes) {
                    //         cout << j.S << " " << deep[j.S] << endl;
                    //     }
                    // }
                    // assert(i != 0);
                    nodes.erase(nodes.begin());
                    if (parent[i] == -1) {
                        i = max(portal[i], 0);
                    } else {
                        i = parent[i];
                    }
                    nodes.emplace(-deep[i], i);
                    road.insert(i);
                }
                int new_i = nodes.begin()->S;
                // cout << new_i << endl;
                for (int i : road) {
                    if (i != new_i) {
                        parent[i] = -1;
                        portal[i] = new_i;
                    }
                }
            
            }
            ++it;
        }
        int res = 0;
        for (int i = 1; i < n; ++i) {
            if (parent[i] != -1) {
                ++res;
            }
            // cout << parent[i] << " " << portal[i] << endl;
        }
        cout << "Case #" << test << ": " << res << endl;
    }
    return 0;
}
