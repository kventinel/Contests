#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<string> v(n);
	for (auto &i : v) {
		cin >> i;
	}
	map<string, int> w;
	for (int i = 0; i < k; ++i) {
		string s;
		cin >> s;
		w[s] = -1;
	}
	ll ans = 0;
	int l = 0;
	int start = 0;
	for (int i = 0; i < n; ++i) {
		if (w.find(v[i]) != w.end()) {
			if (w[v[i]] < start) {
				++l;
			}
			w[v[i]] = i;
		}
		while (k == l) {
			ans += n - i;
			if (w.find(v[start]) != w.end() && w[v[start]] == start) {
				--l;
			}
			++start;
		}
	}
	cout << ans << endl;
	return 0;
}
