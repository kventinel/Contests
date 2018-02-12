#include <iostream>
#include <string>

using namespace std;

int main() {
    string n;
    int a, b;
    cin >> n >> a >> b;
    if (a < b) {
        swap(a, b);
    }
    int j = 0;
    while (j < n.length() && n[j] == '0') {
        ++j;
    }
    n.erase(0, j);
    int l = -1;
    for (int i = n.length() - 1; i >= 0; --i) {
        if (n[i] - '0' > a) {
            l = i + 1;
            n[i] = '0' + a;
        } else if (n[i] - '0' >= a) {
            n[i] = '0' + a;
        } else if (n[i] - '0' > b) {
            l = i + 1;
            n[i] = '0' + b;
        } else if (n[i] - '0' >= b) {
            n[i] = '0' + b;
        } else {
            l = i;
            if (i != 0) {
                n[i - 1]--;
            }
        }
    }
    if (l > 0) {
        for (int i = l; i < n.length(); ++i) {
            n[i] = a + '0';
        }
    } else if (l == 0) {
        for (int i = 1; i < n.length(); ++i) {
            n[i] = a + '0';
        }
        n.erase(0, 1);
    }
    j = 0;
    while (j < n.length() && n[j] == '0') {
        ++j;
    }
    n.erase(0, j);
    if (n.length() != 0) {
        std::cout << n << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
    return 0;
}