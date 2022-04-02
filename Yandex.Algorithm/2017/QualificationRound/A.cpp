#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    map<int, int> data;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        data.insert(make_pair(a, i));
    }
    int k = 1;
    int j = 0;
    while (!data.empty()) {
        if (data.begin()->second < j) {
            ++k;
        }
        j = data.begin()->second;
        data.erase(data.begin());
    }
    cout << k << endl;
    return 0;
}