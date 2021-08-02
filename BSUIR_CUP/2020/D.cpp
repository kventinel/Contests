#include <iostream>
#include <vector>
#include <bitset>
#include <map>

using namespace std;
using ll = long long;

constexpr int N = 1000;

bitset<N> convert(string s) {
    constexpr int M = 15;
    bitset<N> res;
    vector<ll> v;
    int n = s.size();
    ll apd = 1;
    for (int i = 0; i < M; ++i) {
        apd *= 10;
    }
    apd /= 2;
    int steps = (n + M - 1) / M;
    for (int i = 0; i < steps; ++i) {
        v.push_back(0);
        int end = n - i * M;
        int start = max(0, n - (i + 1) * M);
        for (int j = start; j < end; ++j) {
            v[i] *= 10;
            v[i] += s[j] - '0';
        }
    }
    for (int i = 0; v.size() != 0; ++i) {
        if (v[0] & 1) {
            res[i] = 1;
            --v[0];
        }
        for (int j = 0; j < v.size(); ++j) {
            if (v[j] & 1) {
                v[j - 1] += apd;
                v[j] ^= 1;
            }
            v[j] >>= 1;
        }
        if (v[v.size() - 1] == 0) {
            v.erase(v.begin() + v.size() - 1);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<bitset<N>> gauss;

    for (int i = 0; i < n + 1; ++i) {
        string s;
        cin >> s;
        gauss.push_back(convert(s));
    }

    vector<int> p(m);
    for (int i = 0; i < m; ++i) {
        cin >> p[i];
        string s;
        cin >> s;
        gauss.push_back(convert(s));
    }

    vector<bitset<N>> perm(gauss.size());
    for (int i = 1; i < n + 1; ++i) {
        perm[i][i - 1] = 1;
    }
    for (int i = 1; i < n + 1; ++i) {
        if (gauss[i][i - 1] == 0) {
            for (int j = i + 1; ; ++j) {
                if (gauss[j][i - 1]) {
                    swap(gauss[i], gauss[j]);
                    swap(perm[i], perm[j]);
                    break;
                }
            }
        }
        for (int j = i + 1; j < n + 1; ++j) {
            if (gauss[j][i - 1]) {
                gauss[j] ^= gauss[i];
                perm[j] ^= perm[i];
            }
        }
    }

    vector<int> cur(n);
    for (int i = 1; i < n + 1; ++i) {
        cur[i - 1] = i;
    }
    int a = 0;
    for (int i = 0; i < m + 1; ++i) {
        if (gauss[a] != 0) {
            for (int j = 0; j < n; ++j) {
                if (gauss[a][j]) {
                    gauss[a] ^= gauss[cur[j]];
                    perm[a] ^= perm[cur[j]];
                }
            }
        }
        vector<int> ans;
        for (int j = 0; j < N; ++j) {
            if (perm[a][j]) {
                ans.push_back(j + 1);
            }
        }
        cout << ans.size() + 1 << endl << 0;
        for (int j : ans) {
            cout << " " << j;
        }
        cout << endl;
        if (i == m) {
            break;
        }

        int pp = p[i] ^ (ans.size() + 1);
        for (int j : ans) {
            pp ^= j;
        }
        if (pp == 0) {
            a = n + i + 1;
            continue;
        }

        for (int j = 0; j < n; ++j) {
            if (gauss[n + i + 1][j]) {
                gauss[n + i + 1] ^= gauss[cur[j]];
                perm[n + i + 1] ^= perm[cur[j]];
            }
        }
        int pos;
        for (int j = 0; j < cur.size(); ++j) {
            if (perm[cur[j]][pp - 1]) {
                pos = j;
                break;
            }
        }

        perm[n + i + 1] ^= perm[cur[pos]];
        gauss[n + i + 1] = gauss[cur[pos]];
        gauss[cur[pos]] = 0;
        perm[n + i + 1][pp - 1] = 1;
        perm[cur[pos]] ^= perm[n + i + 1];
        for (int j : cur) {
            if (j != cur[pos] && perm[j][pp - 1]) {
                perm[j] ^= perm[cur[pos]];
            }
        }
        if (perm[a][pp - 1]) {
            perm[a] ^= perm[cur[pos]];
        }
        cur[pos] = n + i + 1;
    }
}
