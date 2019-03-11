#include <algorithm>
#include <iostream>
#include <random>
#include <set>
#include <vector>
using namespace std;
using pii = pair<int, int>;
using lll = long long;

int p;
vector<lll> t;
vector<lll> u;

void update(int i, int l, int r) {
    if (i < p && u[i] != 0) {
        t[2 * i] += u[i] * (lll) (r - l) / 2;
        t[2 * i + 1] += u[i] * (lll) (r - l) / 2;
        u[2 * i] += u[i];
        u[2 * i + 1] += u[i];
        u[i] = 0;
    }
}

void add(int i, int l, int r, int ll, int rr, lll val) {
    if (ll <= l && r <= rr) {
        t[i] += val * (lll) (r - l);
        u[i] += val;
        return;
    }
    update(i, l, r);
    int m = (l + r) / 2;
    if (ll < m) {
        add(i * 2, l, m, ll, rr, val);
    }
    if (m < rr) {
        add(i * 2 + 1, m, r, ll, rr, val);
    }
    t[i] = t[2 * i] + t[2 * i + 1];
}

lll get(int i, int l, int r, int u) {
    if (i >= p) {
        return t[i];
    }
    update(i, l, r);
    int m = (l + r) / 2;
    if (u < m) {
        return get(2 * i, l, m, u);
    }
    return get(2 * i + 1, m, r, u);
}

lll sum(int i, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
        return t[i];
    }
    update(i, l, r);
    int m = (l + r) / 2;
    lll ans = 0;
    if (ll < m) {
        ans += sum(i * 2, l, m, ll, rr);
    }
    if (m < rr) {
        ans += sum(i * 2 + 1, m, r, ll, rr);
    }
    return ans;
}

void input(int &n, vector<int> &a, vector<int> &k, vector<pair<char, pii> > &q) {
    cin >> n;
    a.resize(n);
    k.resize(n - 1);
    for (int &i : a) {
        cin >> i;
    }
    for (int &i : k) {
        cin >> i;
    }
    int qq;
    cin >> qq;
    q.resize(qq);
    for (auto &i : q) {
        cin >> i.first >> i.second.first >> i.second.second;
    }
}

vector<lll> solve(int n, vector<int> a, vector<int> k, vector<pair<char, pii> > q) {
    set<pii> s;
    for (int i = 0; i < n; ++i) {
        s.emplace(i, i + 1);
    }
    p = 1;
    while (p < n) {
        p <<= 1;
    }
    t.clear();
    u.clear();
    t.resize(p << 1);
    u.resize(p << 1);
    for (int i = 0; i < n; ++i) {
        t[p + i] = a[i];
    }
    for (int i = p - 1; i > 0; --i) {
        t[i] = t[2 * i] + t[2 * i + 1];
    }
    vector<lll> ans;
    for (auto d : q) {
        char c = d.first;
        if (c == '+') {
            int i = d.second.first;
            lll val = d.second.second;
            --i;
            auto it = s.lower_bound(make_pair(i, p + 1));
            --it;
            if (it->first != i) {
                auto temp = *it;
                s.erase(it);
                s.emplace(temp.first, i);
                s.emplace(i, temp.second);
                it = s.lower_bound(make_pair(i, p + 1));
                --it;
            }
            int first = it->first;
            int second = it->second;
            add(1, 0, p, it->first, it->second, val);
            while (true) {
                second = it->second;
                s.erase(it);
                it = s.lower_bound(make_pair(i, p + 1));
                if (it == s.end()) {
                    break;
                }
                val = get(1, 0, p, it->first - 1) + k[it->first - 1] - get(1, 0, p, it->first);
                if (val <= 0) {
                    break;
                }
                add(1, 0, p, it->first, it->second, val);
            }
            s.emplace(first, second);
        } else {
            int l = d.second.first;
            int r = d.second.second;
            ans.push_back(sum(1, 0, p, l - 1, r));
        }
    }
    return ans;
}

vector<lll> brute(int n, vector<int> a, vector<int> k, vector<pair<char, pii> > q) {
    vector<lll> b;
    for (int i : a) {
        b.push_back(i);
    }
    vector<lll> ans;
    for (auto d : q) {
        if (d.first == '+') {
            int i = d.second.first - 1;
            int val = d.second.second;
            b[i] += val;
            while (i + 1 < n) {
                if (b[i] + k[i] > b[i + 1]) {
                    b[i + 1] = b[i] + k[i];
                } else {
                    break;
                }
                ++i;
            }
        } else {
            int l = d.second.first - 1;
            int r = d.second.second;
            lll sum = 0;
            for (int i = l; i < r; ++i) {
                sum += b[i];
            }
            ans.push_back(sum);
        }
    }
    return ans;
}

void testing() {
    mt19937 gen(42);
    while (true) {
        int n = uniform_int_distribution<>(2, 5)(gen);
        vector<int> a(n);
        vector<int> k(n - 1);
        for (int &i : a) {
            i = uniform_int_distribution<>(-10, 10)(gen);
        }
        for (int &i : k) {
            i = uniform_int_distribution<>(-10, 10)(gen);
        }
        int q = uniform_int_distribution<>(1, 3)(gen);
        vector<pair<char, pii> > qq(q);
        for (auto &i : qq) {
            int a = uniform_int_distribution<>(1, 2)(gen);
            if (a == 1) {
                i.first = '+';
                i.second.first = uniform_int_distribution<>(1, n)(gen);
                i.second.second = uniform_int_distribution<>(0, 10)(gen);
            } else {
                i.first = 's';
                i.second.first = uniform_int_distribution<>(1, n)(gen);
                i.second.second = uniform_int_distribution<>(i.second.first, n)(gen);
            }
        }
        auto ans1 = solve(n, a, k, qq);
        auto ans2 = brute(n, a, k, qq);
        if (ans1.size() != ans2.size()) {
            cout << "WTF" << endl;
            return;
        }
        bool ok = true;
        for (int i = 0; i < ans1.size(); ++i) {
            if (ans1[i] != ans2[i]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            for (int i : ans1) {
                cout << i << " ";
            }
            cout << endl;
            for (int i : ans2) {
                cout << i << " ";
            }
            cout << endl;
            cout << n << endl;
            for (int i : a) {
                cout << i << " ";
            }
            cout << endl;
            for (int i : k) {
                cout << i << " ";
            }
            cout << endl;
            cout << q << endl;
            for (auto i : qq) {
                cout << i.first << " " << i.second.first << " " << i.second.second << endl;
            }
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    //testing();
    //return 0;
    int n;
    vector<int> a;
    vector<int> k;
    vector<pair<char, pii> > q;
    input(n, a, k, q);
    auto ans = solve(n, a, k, q);
    for (auto i : ans) {
        cout << i << endl;
    }
    return 0;
}