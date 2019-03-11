#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pii> v(n);
    for (auto &i : v) {
        cin >> i.first >> i.second;
    }
    int k;
    cin >> k;
    int ans = 0;
    for (auto i : v) {
        ans += i.second >= k;
    }
    cout << ans << endl;
    return 0;
}