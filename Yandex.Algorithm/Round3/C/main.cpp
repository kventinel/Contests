#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    bool ok = true;
    for (int i = 1; i < n && ok; ++i) {
        if (a[i] != a[i - 1]) {
            ok = false;
        }
    }
    if (ok) {
        cout << 0 << endl;
        return 0;
    }
    int l = 1;
    int r = n;
    while (l != r) {
        int i = (r + l) / 2;
        ok = true;
        vector<pair<vector<int>, int>> data;
        vector<int> first;
        for (int j = 0; j < n && ok; ++j) {
            if (first.size() == i) {
                for (int x = 0; x < data.size() && ok; ++x) {
                    if (data[x].second != a[j]) {
                        bool ok2 = true;
                        for (int y = 0; y < first.size() && ok2; ++y) {
                            if (first[y] != data[x].first[y]) {
                                ok2 = false;
                            }
                        }
                        if (ok2) {
                            ok = false;
                        }
                    }
                }
                if (ok) {
                    data.push_back(make_pair(first, a[j]));
                    first.erase(first.begin(), first.begin() + 1);
                    first.push_back(a[j]);
                }
            } else {
                first.push_back(a[j]);
            }
        }
        if (ok) {
            r = i;
        } else {
            if (l == r - 1) {
                break;
            }
            l = i;
        }
    }
    cout << r << endl;
    return 0;
}