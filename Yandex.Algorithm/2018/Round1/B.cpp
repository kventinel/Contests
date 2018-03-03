#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    string s;
    cin >> s;
    vector<int> bits(11);
    bits[0] = 1;
    // set<string> v;
    // set<string> ans;
    for (int i = 1; i < 11; ++i) {
        bits[i] = 2 * bits[i - 1];
    }
    vector<vector<ll>> dp(s.size() + 1, vector<ll> (bits[10] * 10));
    for (int i = 0; i < 10; ++i) {
        dp[0][i] = 1;
    }
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < bits[10] * 10; ++j) {
            if (((j / 10) | bits[s[i] - '0']) != (j / 10) && (j % 10) == (s[i] - '0')) {
                for (int k = 0; k < 10; ++k) {
                    dp[i + 1][((j / 10) | bits[s[i] - '0']) * 10 + k] += dp[i][j];
                }
                dp[i][j] = 0;
            }
            dp[i + 1][j] += dp[i][j];
        }
    }
    // int i = 0;
    // int k = 0;
    // while (true) {
    //     string t = ;
    //     int temp = i;
    //     string tt = 0123456789
    //     for (int j = 0; j < 10; ++j) {

    //     }
    // }
    cout << dp[s.size()][(bits[10] - 1) * 10] << endl;
}
