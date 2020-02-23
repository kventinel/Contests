#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define F first
#define S second
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> w(32, -1);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        int a = v[i];
        int j = 0;
        while (a > 0) {
            if (a & 1) {
                if (w[j] == -1) {
                    w[j] = i;
                } else {
                    w[j] = -2;
                }
            }
            a >>= 1;
            ++j;
        }
    }
    int best_j = -1;
    for (int i : w) {
        if (i >= 0) {
            best_j = i;
        }
    }
    if (best_j > 0) {
        swap(v[0], v[best_j]);
    }
    for (int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
