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

void solve(int w) {
    vector<int> d(7);
    for (int i = 1; i <= w; ++i) {
        cout << i << endl;
        cout.flush();
        cin >> d[i];
    }
    vector<int> ans(7);
    ans[1] = (d[6] - 2 * d[3] - 4 * d[2] + 4 * d[1]) / 40;
    ans[2] = d[2] - d[1] - 2 * ans[1];
    ans[3] = d[3] - d[2] - 4 * ans[1];
    ans[4] = d[4] - d[3] - 8 * ans[1] - 2 * ans[2];
    ans[5] = d[5] - d[4] - 16 * ans[1];
    ans[6] = d[6] - d[5] - 32 * ans[1] - 4 * ans[2] - 2 * ans[3];
    for (int i = 1; i <= 6; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    cout.flush();
    cin >> d[0];
}

int main() {
    int n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; ++i) {
        solve(w);
    }
    return 0;
}