#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

set<pair<int, pair<int, int>>> q;

int main() {
    //freopen(input.txt, r, stdin);
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < s[i].size(); ++j) {
            if (s[i][j] == '.') {
                int res = 0;
                if (j > 0 && s[i][j - 1] == 'S') {
                    ++res;
                }
                if (j < s[i].size() - 1 && s[i][j + 1] == 'S') {
                    ++res;
                }
                q.insert(mp(res, mp(i, j)));
            }
        }
    }
    while (k--) {
        pair<int, pair<int, int>> a = *q.begin();
        q.erase(q.begin());
        s[a.S.F][a.S.S] = 'x';
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < s[i].size(); ++j) {
            if (s[i][j] == 'S') {
                if (j > 0 && s[i][j - 1] != '.' && s[i][j - 1] != '-') {
                    ++ans;
                }
                if (j < s[i].size() - 1 && s[i][j + 1] != '.' && s[i][j + 1] != '-') {
                    ++ans;
                }
            }
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; ++i) {
        cout << s[i] << endl;
    }
    return 0;
}
