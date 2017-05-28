#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n, a;
    cin >> n >> a;
    vector<bool> v(500);
    long long start_a = a;
    for (int i = 0; i < 500; ++i) {
        if (a + start_a <= n) {
            v[a % 500] = true;
        }
        ++a;
    }
    int money = 0;
    a = start_a;
    for (int i = 0; i < 500; ++i) {
        if (v[i % 500]) {
            int temp_ans = 1000;
            if (i % 500 == 0) {
                temp_ans -= 500;
            } else {
                temp_ans -= i;
            }
            if ((n - i) % 500 == 0) {
                temp_ans -= 500;
            } else {
                temp_ans -= (n - i) % 500;
            }
            money = max(money, temp_ans);
        }
    }
    cout << money << endl;
    return 0;
}