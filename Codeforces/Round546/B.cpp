#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    cout << 3 * n + min(k - 1, n - k) << endl;
    return 0;
}