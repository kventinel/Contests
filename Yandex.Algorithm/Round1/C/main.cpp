#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > ribs(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        if (b < a) {
            int temp = a;
            a = b;
            b = temp;
        }
        ribs[b].push_back(a);
    }
    vector<int> vertex(n, 1);
    int k = 1;
    for (int i = 1; i < n; ++i) {
        vector<int> temp;
        for (int j = 0; j < ribs[i].size(); ++j) {
            temp.push_back(vertex[ribs[i][j]]);
        }
        sort(temp.begin(), temp.end());
        int choose = 1;
        for (int j = 0; j < temp.size(); ++j) {
            if (temp[j] == choose) {
                ++choose;
            }
        }
        if (choose > k) {
            ++k;
        }
        vertex[i] = choose;
    }
    cout << k << endl;
    for (int i = 0; i < n; ++i) {
        cout << vertex[i] << " ";
    }
    return 0;
}