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
using ll = long long;

uint64_t mod = (1ULL << 63);

__uint128_t pow(__uint128_t i, int step) {
    __uint128_t ans = 1;
    for (int j = 0; j < step; ++j) {
        ans *= i;
        ans %= mod;
    }
    return ans;
}

void solve(int w) {
    vector<__uint128_t> d(500);
    vector<int> q{56, 169, 1, 2, 3, 4};
    q.erase(q.begin() + w, q.end());
    for (int i : q) {
        cout << i << endl;
        cout.flush();
        ll a;
        cin >> a;
        d[i] = a;
    }
    vector<uint32_t> ans(7);
    ans[1] = (d[56] / pow(2, 56));
    d[56] -= ans[1] * pow(2, 56);
    d[169] -= ans[1] * pow(2, 169);
    ans[2] = (d[56] / pow(2, 28));
    d[56] -= ans[2] * pow(2, 28);
    d[169] -= ans[2] * pow(2, 84);
    d[169] %= mod;
    ans[3] = (d[169] / pow(2, 56));
    d[56] -= ans[3] * pow(2, 18);
    d[169] -= ans[3] * pow(2, 56);
    ans[4] = (d[169] / pow(2, 42));
    d[56] -= ans[4] * pow(2, 14);
    d[169] -= ans[4] * pow(2, 42);
    d[6] = (pow(2, 22) * d[56] - d[169]) / (pow(2, 31) - pow(2, 28));
    d[5] = d[56] - pow(2, 9) * ans[6];
    for (int i = 1; i <= 6; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    cout.flush();
    int val;
    cin >> val;
}

int main() {
    int n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; ++i) {
        solve(w);
    }
    return 0;
}