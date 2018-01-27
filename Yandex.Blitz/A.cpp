#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> v(n, vector<int> (m));
	while (k-- > 0) {
		int i, j;
		cin >> i >> j;
		v[--i][--j] = 1;
	}
	k = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (v[i][j] == 0) {
				stack<pair<int, int>> q;
				q.push(make_pair(i, j));
				v[i][j] = 1;
				while (!q.empty()) {
					int a, b;
					a = q.top().first;
					b = q.top().second;
					q.pop();
					if (a > 0 && v[a - 1][b] == 0) {
						q.push(make_pair(a - 1, b));
						v[a - 1][b] = 1;
					}
					if (a + 1 < n && v[a + 1][b] == 0) {
						q.push(make_pair(a + 1, b));
						v[a + 1][b] = 1;
					}
					if (b > 0 && v[a][b - 1] == 0) {
						q.push(make_pair(a, b - 1));
						v[a][b - 1] = 1;
					}
					if (b + 1 < m && v[a][b + 1] == 0) {
						q.push(make_pair(a, b + 1));
						v[a][b + 1] = 1;
					}
				}
				++k;
			}

		}
	}
	cout << k << endl;
	return 0;
}