#include <bits/stdc++.h>

#define pb push_back

using namespace std;

using ll = long long;

ll w;

struct race;

struct pp{
    ll F, S;

    pp(ll a, ll b) {
        F = a;
        S = b;
    }

    bool operator<(const race& other) const;
};

struct race {
    ll x, y;
    int i;

    race(ll xx, ll yy) : x(xx), y(yy) {}

    bool operator<(const race& other) const {
        if (x * (other.y + w) != other.x * (y + w)) {
            return x * (other.y + w) < other.x * (y + w);
        }
        return x * (other.y - w) > other.x * (y - w);
    }

    bool operator<(const pp& other) const {
        return x * other.S < other.F * (y + w);
    }
};

bool pp::operator<(const race& other) const {
    return F * (other.y + w) < other.x * S;
}

ll ans(vector<race>& v) {
    int p = 1;
    while (p < v.size() + 1) {
        p <<= 1;
    }
    for (int i = 0; i < v.size(); ++i) {
        v[i].i = i;
    }
    sort(v.begin(), v.end(), [](const race& a, const race& b){
        if (a.x * (b.y - w) != b.x * (a.y - w)) {
            return a.x * (b.y - w) < b.x * (a.y - w);
        }
        return a.i > b.i;
    });
    vector<ll> w(p << 1);
    ll k = 0;
    for (auto &i : v) {
        int u = p + i.i + 1;
        while (u > 1) {
            if ((u & 1) != 0) {
                k += w[u];
                ++u;
            }
            u >>= 1;
        }
        u = p + i.i + 1;
        while (u > 0) {
            ++w[u];
            u >>= 1;
        }
    }
    return k;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n >> w;
    vector<race> left;
    vector<race> right;
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        if (x < 0) {
            left.pb(race(-x, y));
        } else {
            right.pb(race(x, -y));
        }
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    ll k = 0;
    for (auto &i : left) {
        k += upper_bound(right.begin(), right.end(), pp(i.x, i.y - w)) -
                lower_bound(right.begin(), right.end(), pp(i.x, i.y + w));
    }
    for (auto &i : right) {
        k += upper_bound(left.begin(), left.end(), pp(i.x, i.y - w)) -
                upper_bound(left.begin(), left.end(), pp(i.x, i.y + w));
    }
    k += ans(left);
    k += ans(right);
    cout << k << endl;
    return 0;
}
