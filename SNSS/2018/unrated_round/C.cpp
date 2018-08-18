#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

vector<string>
foo(string s, int k, string res) {
    if (k * 3 < s.size()) {
        return vector<string>(0);
    }
    if (k == 1 && (s.size() == 1 || s[0] != '0')) {
        if (stoi(s) >= 256) {
            return vector<string>(0);
        }
        return vector<string>{res + "." + s};
    }
    vector<string> ans;
    for (int i = 0; i < min(3, (int) s.size() - 1); ++i) {
        if (i == 2 && stoi(s.substr(0, i + 1)) >= 256) {
            break;
        }
        vector<string> temp = foo(s.substr(i + 1), k - 1, res + "." + s.substr(0, i + 1));
        ans.insert(ans.end(), temp.begin(), temp.end());
        if (s[0] == '0') {
            break;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    vector<string> temp = foo(s, 4, "");
    for (auto e : temp) {
        cout << e.substr(1) << endl;
    }
    return 0;
}
