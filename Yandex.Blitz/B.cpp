#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<int> v(n);
	vector<vector<int>> edges(n);
	for (int i = 0; i + 1 < n; ++i) {
		int a, b;
		cin >> a >> b;
		edges[--a].push_back(--b);
		v[b] = a;
	}
	vector<vector<int>> deep(n);
	deep[0].push_back(0);
	for (int i = 0; i + 1 < n; ++i) {
		for (int j : deep[i]) {
			for (int l : edges[j]) {
				deep[i + 1].push_back(l);
			}
		}
	}
	vector<pair<int, int>> res(n);
	for (int i = 0; i < n; ++i) {
		res[i].first = 1;
		res[i].second = 1;
		if (s[i] != '.') {
			if (s[i] == '+') {
				res[i].first = 1;
				res[i].second = -1;
			} else if(s[i] == '-') {
				res[i].first = -1;
				res[i].second = 1;
			} else {
				res[i].first = 0;
				res[i].second = 0;
			}
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int a : deep[i]) {
			if (i == k && edges[a].size() != 0) {
				res[a].first = min(res[a].first, res[a].second);
			}
			if (a != 0) {
				res[v[a]].first = min(res[v[a]].first, -res[a].first);
				res[v[a]].second = min(res[v[a]].second, -res[a].second);
			}
		}
	}
	if (res[0].first == -1) {
		cout << "First\n";
	} else if (res[0].first == 0) {
		cout << "Draw\n";
	} else {
		cout << "Second\n";
	}
	return 0;
}