#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;
    while (tests-- > 0) {
        uint64_t n;
        cin >> n;
        int k = 1;
        while (true) {
            vector<int> v;
            uint64_t temp = n * k;
            int l = 0;
            while (temp != 0) {
                if (temp % 2 != 0) {
                    --temp;
                    v.push_back(l);
                    if (v.size() > k) {
                        break;
                    }
                }
                temp /= 2;
                ++l;
            }
            if (v.size() > k) {
                ++k;
                continue;
            }
            while (v.size() != k) {
                v[v.size() - 1]--;
                v.push_back(v[v.size() - 1]);
            }
            cout << k << " ";
            for (int i : v) {
                cout << " " << i;
            }
            cout << endl;
            break;
        }
    }
    return 0;
}