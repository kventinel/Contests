#include <iostream>
#include <vector>

int main() {
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<int>> v(n, std::vector<int> (m));
        int c = 1;
        for (int l = 0; l + 1 < n + m; ++l) {
            int i = l;
            int j = 0;
            if (i >= n) {
                i = n - 1;
                j = l - n + 1;
            }
            while (true) {
                v[i][j] = c;
                ++c;
                --i;
                ++j;
                if (i < 0 || j >= m) {
                    break;
                }
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                std::cout << v[i][j];
                if (j == 0) {
                    std::cout << std::endl;
                } else {
                    std::cout << " ";
                }
            }
        }
    }
    return 0;
}