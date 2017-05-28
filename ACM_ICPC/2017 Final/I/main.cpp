#include <iostream>
#include <vector>
#include <queue>

int main() {
    int m, n;
    std::cin >> m >> n;
    std::vector<std::vector<int>> edge(26);
    while (m-- > 0) {
        char a, b;
        std::cin >> a >> b;
        edge[a - 'a'].push_back(b - 'a');
    }
    while (n-- > 0) {
        std::string a, b;
        std::cin >> a >> b;
        if (a.size() != b.size()) {
            std::cout << "no\n";
            continue;
        }
        bool is_true = true;
        for (int i = 0; i < a.size(); ++i) {
            std::vector<bool> label(26, false);
            int ta = a[i] - 'a';
            label[ta] = true;
            std::queue<int> search;
            search.push(ta);
            while (!search.empty()) {
                ta = search.front();
                search.pop();
                for (int j = 0; j < edge[ta].size(); ++j) {
                    if (!label[edge[ta][j]]) {
                        label[edge[ta][j]] = true;
                        search.push(edge[ta][j]);
                    }
                }
            }
            if (!label[b[i] - 'a']) {
                is_true = false;
                break;
            }
        }
        if (is_true) {
            std::cout << "yes\n";
        } else {
            std::cout << "no\n";
        }
    }
    return 0;
}