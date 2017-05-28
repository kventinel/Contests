#include <iostream>
#include <set>
#include <vector>

int main() {
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test) {
        int n;
        std::cin >> n;
        std::set<int> cubs;
        for (int i = 1; i <= n; ++i) {
            cubs.insert(i);
        }
        std::vector<int> data(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> data[i];
            cubs.erase(data[i]);
        }
        bool biggest = true;
        for (int i = 0; i < n; ++i) {
            if (data[i] == 0) {
                if (biggest) {
                    auto temp = cubs.end();
                    --temp;
                    data[i] = *temp;
                    cubs.erase(temp);
                    biggest = false;
                } else {
                    data[i] = *cubs.begin();
                    cubs.erase(cubs.begin());
                }
            }
        }
        for
    }
    return 0;
}