#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    multiset<ll> s;
    ll update = 0;
    for (int i = 0; i < n; ++i) {
        ll ans = 0;
        ll a;
        cin >> a;
        s.insert(v[i] + update);
        while (s.size() != 0 && *s.begin() <= a + update) {
            ans += *s.begin() - update;
            s.erase(s.begin());
        }
        ans += a * s.size();
        update += a;
        cout << ans <<  ;
    }
    cout << endl;
    return 0;
}
