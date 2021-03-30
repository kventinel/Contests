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

const int N = 100;
const int M = 10000;

ld true_score(const string &v, ld p, const vector<ld> &q) {
    ld score = 0;
    for (int j = 0; j < M; ++j) {
        if (v[j] == '0') {
            score += log(1.0 - 1.0 / (1.0 + exp(-p + q[j])));
        } else {
            score += log(1.0 / (1.0 + exp(-p + q[j])));
        }
    }
    return score;
}

ld cheat_score(const string &v, ld p, const vector<ld> &q) {
    ld score = 0;
    for (int j = 0; j < M; ++j) {
        if (v[j] == '0') {
            score += log(0.5 - 0.5 / (1.0 + exp(-p + q[j])));
        } else {
            score += log(0.5 + 0.5 / (1.0 + exp(-p + q[j])));
        }
    }
    return score;
}

int get_cheat(const vector<string> &v, const vector<ld> &p, const vector<ld> &q) {
    ld mlk = -1e9;
    int bp = 0;
    for (int i = 0; i < N; ++i) {
        ld cur = cheat_score(v[i], p[i], q) - true_score(v[i], p[i], q);
        if (cur > mlk) {
            mlk = cur;
            bp = i;
        }
    }
    return bp;
}

ld calc_mlk(const vector<string> &v, const vector<ld> &p, const vector<ld> &q, int bp) {
    ld mlk = 0;
    for (int i = 0; i < N; ++i) {
        if (i != bp) { 
            mlk += true_score(v[i], p[i], q);
        } else {
            mlk += cheat_score(v[i], p[i], q);
        }
    }
    return mlk;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tt, p;
    cin >> tt >> p;
    random_device rd;
    mt19937 r(rd());
    uniform_real_distribution<> dst(-3.0, 3.0);
    for (int t = 1; t <= tt; ++t) {
        vector<string> v(N);
        vector<int> tap(N);
        vector<int> taq(M);
        vector<pii> ptap(N);
        vector<pii> ptaq(M);
        for (int i = 0; i < M; ++i) {
            ptaq[i].S = i;
        }
        for (int i = 0; i < N; ++i) {
            cin >> v[i];
            ptap[i].S = i;
            for (int j = 0; j < M; ++j) {
                tap[i] += v[i][j] - '0';
                taq[j] += v[i][j] - '0';
                ptap[i].F += v[i][j] - '0';
                ptaq[j].F += v[i][j] - '0';
            }
        }
        sort(ptap.begin(), ptap.end());
        sort(ptaq.begin(), ptaq.end());
        // int bp = 0;
        // ld res = -1e9;
        vector<ld> sq(M);
        vector<ld> sp(N);
        vector<ld> q(M);
        vector<ld> p(N);
        for (int step = 0; step < 1; ++step) {
            for (int i = 0; i < N; ++i) {
                // p[i] = dst(r);
                sp[i] = dst(r);
            }
            for (int j = 0; j < M; ++j) {
                // q[j] = dst(r);
                sq[j] = dst(r);
            }
            sort(sq.rbegin(), sq.rend());
            sort(sp.begin(), sp.end());
            for (int i = 0; i < N; ++i) {
                p[ptap[i].S] = sp[i];
            }
            for (int j = 0; j < M; ++j) {
                q[ptaq[j].S] = sq[j];
            }
        //     // ld bscore = 0;
        //     for (int i = 0; i < N; ++i) {
        //         if (tap[i] < M / 2) {
        //             continue;
        //         }
        //         int good = (tap[i] - M / 2) * 2;
        //         int j = 0;
        //         for (; j < N; ++j) {
        //             if (good < ptap[j].F) {
        //                 break;
        //             }
        //         }
        //         ld score = sp[ptap[j].S];
        //         ld cur = cheat_score(v[i], score, q) - 0.7 * true_score(v[i], p[i], q);
        //         if (cur > res) {
        //             res = cur;
        //             bp = i;
        //             // bscore = score;
        //         }
        //     }
        }
        // p[bp] = bscore;
        // for (int step = 0; step < 0; ++step) {
        //     vector<ld> new_q(M);
        //     vector<ld> new_p(N);
        //     vector<ld> sq = q;
        //     vector<ld> sp = p;
        //     sort(sq.begin(), sq.end());
        //     sort(sp.rbegin(), sp.rend());
        //     for (int i = 0; i < N; ++i) {
        //         new_p[i] = min(max((sq[tap[i] - 1] + sq[tap[i]]) / 2, (ld) -3), (ld) 3);
        //     }
        //     for (int i = 0; i < M; ++i) {
        //         new_q[i] = min(max((sp[taq[i] - 1] + sp[taq[i]]) / 2, (ld) -3), (ld) 3);
        //     }
        //     // cerr << get_cheat(v, p, q) << " " << calc_mlk(v, p, q, get_cheat(v, p, q)) << " " << p[0] << " " << q[0] << endl;
        //     p = move(new_p);
        //     q = move(new_q);
        // }
        // bp = get_cheat(v, p, q);
        // cerr << bp << " " << calc_mlk(v, p, q, bp) << " " << p[0] << " " << q[0] << endl;
        //
        int score = 0;
        int bp = 0;
        vector<pii> ntap(N);
        for (int i = 0; i < N; ++i) {
            int s = 0;
            for (int j = 0; j < 200; ++j) {
                if (ptaq[j].F <= 100) {
                    s += v[i][ptaq[j].S] - '0';
                }
            }
            ntap[i].F = s;
            ntap[i].S = i;
        }
        bool end = false;
        sort(ntap.rbegin(), ntap.rend());
        vector<int> cnt(N);
        ld ch_score = -1e9;
        // for (int j = M - 1; j > 0; --j) {
        //     for (int i = 0; i < 5; ++i) {
        //         if (v[ntap[i].S][ptaq[j].S] == '0') {
        //             cnt[i]++;
        //             if (cnt[i] == 200) {
        //                 bp = ntap[i].S;
        //                 end = true;
        //                 break;
        //             }
        //         }
        //     }
        //     if (end) {
        //         break;
        //     }
        // }
        for (int i = 0; i < 5; ++i) {
            int id = ntap[i].S;
            // int good = (tap[id] - M / 2) * 2;
            // int j = 0;
            // for (; j < N; ++j) {
            //     if (good < ptap[j].F) {
            //         break;
            //     }
            // }
            ld max_cheat = -1e9;
            ld max_true = -1e9;
            for (ld power = -3; power <= 3 + 1e-9; power += 0.1) {
                max_cheat = max(max_cheat, cheat_score(v[id], power, q));
                max_true = max(max_true, true_score(v[id], power, q));
            }
            // ld cur = max_cheat;
            ld cur = max_cheat - max_true;
            // ld cur = cheat_score(v[id], p[id], q) - true_score(v[id], p[id], q);
            // ld cur = tap[id];
            if (cur > ch_score) {
                ch_score = cur;
                bp = id;
            }
        }
        cout << "Case #" << t << ": " << bp + 1 << endl;
    }
    return 0;
}