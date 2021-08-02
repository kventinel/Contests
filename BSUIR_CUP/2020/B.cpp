#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    string s = "BSUIROPENX";
    vector<int> start(s.length());
    vector<int> end(s.length());
    int n;
    cin >> n;
    while (n--) {
        string t;
        cin >> t;
        if (t.length() >= s.length()) {
            continue;
        }
        if (s.substr(0, t.length()) == t) {
            start[t.length()]++;
        }
        if (s.substr(s.length() - t.length()) == t) {
            end[s.length() - t.length()]++;
        }
    }
    ll ans = 0;
    for (int i = 0; i < s.length(); ++i) {
        ll a = start[i];
        a *= end[i];
        ans += a;
    }
    cout << ans << endl;
}
