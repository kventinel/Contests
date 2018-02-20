#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> v(2 * n, vector<int> (n));
	for (auto &i : v) {
		for (auto &j : i) {
			cin >> j;
		}
	}
	vector<bool> w(n * n + 1, false);
	vector<vector<int>> ans(n);
	vector<int> first_col;
	for (int i = 0; i < 2 * n; ++i) {
		if (w[v[i][0]]) {
			first_col = v[i];
		} else {
			w[v[i][0]] = true;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2 * n; ++j) {
			if (first_col[i] == v[j][0]) {
				for (int k = 0; k < n; ++k) {
					cout << v[j][k] << " ";
				}
				break;
			}
		}
	}
	cout << endl;
	return 0;
}
