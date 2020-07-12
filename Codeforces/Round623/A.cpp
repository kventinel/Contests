#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define F first
#define S second
#define pb push_back
#define eb emplace_back

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    vector<pii> v(n);
    for (pii &i : v) {
        cin >> i.F;
    }
    for (pii &i : v) {
        cin >> i.S;
    }
    int pos = 0;
    multiset<int> s;
    ll sum = 0;
    ll ans = 0;
    sort(v.begin(), v.end());
    for (pii i : v) {
        while (pos < i.F && !s.empty()) {
            sum -= *s.rbegin();
            s.erase(--s.end());
            ans += sum;
            ++pos;
        }
        pos = i.F;
        s.insert(i.S);
        sum += i.S;
    }
    while (!s.empty()) {
        sum -= *s.rbegin();
        s.erase(--s.end());
        ans += sum;
    }
    cout << ans << endl;
    return 0;
}
