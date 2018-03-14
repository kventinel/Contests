#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

using ll = long long;
using ld = long double;

struct Node {
    Node* zero;
    Node* one;
    Node* father;
    int k = 0;
};

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    string t;
    int n;
    cin >> s >> t >> n;
    vector<int> sbc(s.size() + 1);
    vector<int> sa(s.size() + 1);
    vector<int> tbc(t.size() + 1);
    vector<int> ta(t.size() + 1);
    for (int i = 0; i < s.size(); ++i) {
        sbc[i + 1] = sbc[i] + (s[i] != 'A' ? 1 : 0);
        if (s[i] == 'A') {
            sa[i + 1] = sa[i] + 1;
        } else {
            sa[i + 1] = 0;
        }
    }
    for (int i = 0; i < t.size(); ++i) {
        tbc[i + 1] = tbc[i] + (t[i] != 'A' ? 1 : 0);
        if (t[i] == 'A') {
            ta[i + 1] = ta[i] + 1;
        } else {
            ta[i + 1] = 0;
        }
    }
    while (n--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a;
        --c;
        int sum = sbc[b] - sbc[a] - tbc[d] + tbc[c];
        int temps = sa[b];
        int tempt = ta[d];
        if (sa[b] - sa[a] == b - a) {
            temps = b - a;
        }
        if (ta[d] - ta[c] == d - c) {
            tempt = d - c;
        }
        int suma = temps - tempt;
        if (sum % 2 != 0 || sum > 0) {
            cout << 0;
        } else if (suma < 0) {
            cout << 0;
        } else if (suma % 3 != 0 && sum == 0) {
            cout << 0;
        } else if (suma == 0 && sbc[b] - sbc[a] == 0 && sum != 0) {
            cout << 0;
        } else {
            cout << 1;
        }
    }
    cout << endl;
    return 0;
}
