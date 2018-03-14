#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    int n = 1000001;
    vector<int> v(n);
    for (int i = 2; i < n; ++i) {
        if (v[i] == 0) {
            for (int j = i * 2; j < n; j += i) {
                v[j] = i;
            }
        }
    }
    int k = n;
    cin >> n;
    for (int i = n - v[n] + 1; i <= n; ++i) {
        k = min(k, i - v[i] + 1);
    }
    cout << k << endl;
    return 0;
}
