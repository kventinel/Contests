#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    if (a.size() != b.size()) {
        cout << -1 << endl;
        return 0;
    } else if (a == b) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> ac(26, 0);
    vector<int> bc(26, 0);
    for (int i = 0; i < a.size(); ++i) {
        ac[a[i] - 'a']++;
        bc[b[i] - 'a']++;
    }
    for (int i = 0; i < 26; ++i) {
        if (ac[i] != bc[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    vector<vector<int>> dp(a.size() + 1, vector<int>(a.size() + 1, -100000));
    vector<int> symb(26, 0);
    dp[0][0] = 0;
    for (int i = 1; i <= a.size(); ++i) {
        symb[b[i - 1] - 'a']++;
        std::vector<int> temp1(26, 0);
        for (int j = 0; j < a.size(); ++j) {
            temp1[a[j] - 'a']++;
            if (a[j] == b[i - 1]) {
                std::vector<int> temp2(26, 0);
                for (int l = j + 1; l <= i; ++l) {
                    if (temp1[a[l - 1] - 'a'] + temp2[a[l - 1] - 'a'] <= symb[a[l - 1] - 'a']) {
                        dp[i][l] = max(dp[i][l], dp[i - 1][j] + 1);
                    } else {
                        break;
                    }
                    if (l < i) {
                        temp2[a[l] - 'a']++;
                    }
                }
            }
            if (a[j] != b[i - 1] || symb[a[j] - 'a'] != temp1[a[j] - 'a']) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }
    }
    int m = 0;
    for (int j = 0; j <= a.size(); ++j) {
        m = max(m, dp[a.size()][j]);
    }
    cout << a.size() - m << endl;
    return 0;
}