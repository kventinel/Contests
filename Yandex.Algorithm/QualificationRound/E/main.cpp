#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    uint64_t res = 1;
    uint64_t mod = 1000 * 1000 * 1000 + 7;
    uint64_t k = n - 3;
    for (int i = 1; i < n; ++i) {
        res *= i;
        res %= mod;
    }
    for (int i = 1; i + 2 < n; ++i) {
        k += i;
    }
    if (res % 2 != 0) {
        res += mod;
    }
    res /= 2;
    res *= k;
    res %= mod;
    cout << res << endl;
    return 0;
}