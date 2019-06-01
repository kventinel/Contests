#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using pii = pair<int, int>;

pii solve(int q, vector<int> &north, vector<int> &south, vector<int> &west, vector<int> &east) {
    int n = 1;
    while (n < q) {
        n *= 2;
    }
    vector<pii> t(2 * n);
    pii ans = {0, 0};
    int score = west.size();
    int best = -1;
    sort(north.begin(), north.end());
    sort(south.begin(), south.end());
    sort(west.begin(), west.end());
    sort(east.begin(), east.end());
    auto wi = west.begin();
    auto ei = east.begin();
    for (int i = 0; i < q; ++i) {
        while (wi != west.end() && *wi == i) {
            --score;
            ++wi;
        }
        if (score > best) {
            best = score;
            ans.first = i;
        }
        while (ei != east.end() && *ei == i) {
            ++score;
            ++ei;
        }
    }
    score = south.size();
    best = -1;
    auto si = south.begin();
    auto ni = north.begin();
    for (int i = 0; i < q; ++i) {
        while (si != south.end() && *si == i) {
            --score;
            ++si;
        }
        if (score > best) {
            best = score;
            ans.second = i;
        }
        while (ni != north.end() && *ni == i) {
            ++score;
            ++ni;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int p, q;
        cin >> p >> q;
        vector<int> north;
        vector<int> south;
        vector<int> west;
        vector<int> east;
        for (int j = 0; j < p; ++j) {
            int x, y;
            char d;
            cin >> x >> y >> d;
            switch(d) {
                case 'N':
                    north.emplace_back(y);
                    break;
                case 'S':
                    south.emplace_back(y);
                    break;
                case 'W':
                    west.emplace_back(x);
                    break;
                case 'E':
                    east.emplace_back(x);
                    break;
            }
        }
        ++q;
        pii ans = solve(q, north, south, west, east);
        cout << "Case #" << i << ": " << ans.first << " " << ans.second << endl;
    }
    return 0;
}