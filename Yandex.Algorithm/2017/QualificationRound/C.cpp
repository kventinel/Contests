#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    long long two = 1;
    long long res1 = 0;
    long long res2 = 0;
    int k = 0;
    int n;
    cin >> n;
    vector<int> times(n);
    for (int &time : times) {
        cin >> time;
        res1 += time;
    }
    vector<vector<int>> tree(n);
    for (auto& node : tree) {
        int m;
        cin >> m;
        node.resize(m);
        for (int& rib : node) {
            cin >> rib;
            --rib;
        }
    }
    queue<pair<int, int>> q({{0, 0}});
    while (!q.empty()) {
        if (k < q.front().second) {
            ++k;
            two *= 2;
        }
        int node = q.front().first;
        q.pop();
        res2 += two * times[node];
        for (int rib : tree[node]) {
            q.push({rib, k + 1});
        }
    }
    cout << res1 << " " << res2 << endl;
    return 0;
}
