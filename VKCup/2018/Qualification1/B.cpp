#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        int l = max(0, i - k);
        int r = min(n - 1, i + k);
        if (x == -1) {
            ans[i] = r - l + 1;
        } else {
            l = max(l, min(x + k + 1, n));
            ans[i] = ans[x] + r - l + 1;
        }
    }
    for (auto i : ans) {
        cout << i <<  ;
    }
    return 0;
}
