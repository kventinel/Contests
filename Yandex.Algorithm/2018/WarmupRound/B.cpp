#include <bits/stdc++.h>

using namespace std;

int main() {
string s;
cin >> s;
string ans = ;
for (int i = 1; i < s.size(); ++i) {
if (s[i - 1] == s[i]) {
if (ans ==  || s[i - 1] < ans[0]) {
ans = s[i - 1];
ans += s[i];
}
}
}
if (ans == ) {
for (int i = 2; i < s.size(); ++i) {
if (s[i - 2] == s[i]) {
if (ans ==  || s[i - 2] < ans[0] || (s[i - 2] == ans[0] && s[i - 1] < ans[1])) {
ans = s[i - 2];
ans += s[i - 1];
ans += s[i];
}
}
}
}
if (ans == ) {
cout << -1 << endl;
} else {
cout << ans << endl;
}
}
