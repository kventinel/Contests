#include <iostream>
#include <cmath>

int main() {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    bool gor = false;
    if (fabs(x1 - x2) > fabs(y1 - y2)) {
        gor = true;
    }
    int k = 0;
    while (x1 != x2 || y1 != y2) {
        if (gor) {
            if (x1 <= x2) {
                ++x1;
            } else {
                --x1;
            }
        } else {
            if (y1 <= y2) {
                ++y1;
            } else {
                --y1;
            }
        }
        gor = !gor;
        ++k;
    }
    std::cout << k << std::endl;
    return 0;
}