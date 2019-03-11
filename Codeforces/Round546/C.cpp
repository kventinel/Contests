#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n + m - 1);
    vector<vector<int> > b(n + m - 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int c;
            cin >> c;
            a[i + j].push_back(c);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int c;
            cin >> c;
            b[i + j].push_back(c);
        }
    }
    for (int i = 0; i < n + m - 1; ++i) {
        sort(a[i].begin(), a[i].end());
        sort(b[i].begin(), b[i].end());
        for (int j = 0; j < a[i].size(); ++j) {
            if (a[i][j] != b[i][j]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}