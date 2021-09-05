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
        int n;
        cin >> n;
        vector<int> c(n);
        for (int& i : c) {
            cin >> i;
        }
        vector<pair<int, int> > edges(n - 1);
        for (auto& i : edges) {
            cin >> i.first >> i.second;
        }
        stack<int> s;
        queue<int> q;
        vector<int> p(n + 1, -1);
        p[1] = 0;
        q.push(1);
        while(!q.empty()) {
            int a = q.front();
            q.pop();
            s.push(a);
            for (auto &i : edges) {
                if (i.first == a && p[i.second] == -1) {
                    q.push(i.second);
                    p[i.second] = a;
                } else if (i.second == a && p[i.first] == -1) {
                    q.push(i.first);
                    p[i.first] = a;
                }
            }
        }
        vector<pii> res(n + 1);
        while (!s.empty()) {
            int a = s.top();
            s.pop();
            if (p[a] != 0) {
                int cur = res[a].first + c[a - 1];
                if (p[a] == 1) {
                    if (res[p[a]].first < cur) {
                        res[p[a]].second = res[p[a]].first;
                        res[p[a]].first = cur;
                    } else if (res[p[a]].second < cur) {
                        res[p[a]].second = cur;
                    }
                } else {
                    if (res[p[a]].first < cur) {
                        res[p[a]].first = cur;
                    }
                }
            }
        }
        cout << "Case #" << test << ": " << res[1].first + res[1].second + c[0] << endl;
    }
    return 0;
}
