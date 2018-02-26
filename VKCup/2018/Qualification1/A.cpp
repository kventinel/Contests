#include <iostream>
#include <string>

using namespace std;

void remake(string& s) {
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
        }
        if (s[i] == 'o') {
            s[i] = '0';
        }
        if (s[i] == 'l' || s[i] == 'i') {
            s[i] = '1';
        }
    }
}

int main() {
    string s, g;
    int n;
    cin >> s;
    remake(s);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> g;
        remake(g);
        if (s == g) {
            cout << No << endl;
            return 0;
        }
    }
    cout << Yes << endl;
    return 0;
}
