#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    map<int, int> set;
    while (n-- > 0) {
        int a, b;
        cin >> a >> b;
        auto first = set.upper_bound(a);
        while (first != set.end() && first->first <= b) {
            b = first->second > b ? first->second : b;
            auto temp = first;
            ++temp;
            set.erase(first);
            first = temp;
        }
        if (first != set.begin()) {
            --first;
            if (first != set.end() && first->second >= a) {
                a = first->first;
                b = first->second > b ? first->second : b;
            }
        }
        set[a] = b;
        cout << set.size() << endl;
    }
}
