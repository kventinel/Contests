#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int d = sqrt(n);
    if (d * d < n) {
        ++d;
    }
    cout << d << endl;
    return 0;
}

