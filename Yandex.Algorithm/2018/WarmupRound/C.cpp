#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

pair<int, int> get_centre() {
int type;
cin >> type;
if (type == 0) {
int r, x, y;
cin >> r >> x >> y;
return make_pair(x * 2, y * 2);
}
int x1, y1, x2, y2, x3, y3, x4, y4;
cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
return make_pair((x1 + x2 + x3 + x4) / 2, (y1 + y2 + y3 + y4) / 2);
}

int main() {
ios_base::sync_with_stdio(false);
int n;
cin >> n;
if (n == 1) {
cout << YESn;
return 0;
}
pair<ll, ll> f = get_centre();
pair<ll, ll> s = get_centre();
n -= 2;
while (n > 0 && f == s) {
s = get_centre();
--n;
}
ll A = s.second - f.second;
ll B = f.first - s.first;
ll C = f.second * s.first - f.first * s.second;
while (n > 0) {
--n;
s = get_centre();
if (A * s.first + B * s.second + C != 0) {
cout << NOn;
return 0;
}
}
cout << YESn;
return 0;
}
