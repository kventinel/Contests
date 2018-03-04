#include <iostream>
#include <vector>

using namespace std;

typedef long double ld;

int main() {
	const int n = 10;
	vector<vector<ld>> c(n, vector<ld>(n));
	vector<ld> a(n);
	a[0] = 1;
	c[0][0] = 1;
	for (int i = 1; i < n; ++i) {
		a[i] = a[i - 1] * i;
		c[i][0] = 1;
		for (int j = 1; j < n; ++j) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	for (int i = 1; i < n; ++i) {
		ld ans = 0;
		ld k = 1;
		for (int j = 2; j <= i; ++j) {
			ans += k * c[i][j] * a[i - j];
			k *= -1;
		}
		cout << i << " " << ans / a[i] << endl;
	}
}