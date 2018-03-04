#include <iostream>
#include <vector>

using namespace std;

int main() {
	const long long MOD = 1000000000000000000L;
	long long m = 5000;
	vector<bool> v(m * m, true);
	vector<long long> ans(m * m);
	ans[0] = 1;
	long long res = 0;
	for (long long i = 2; i < m * m; ++i) {
		if (v[i]) {
			for (long long j = 2; i * j < m * m; ++j) {
				v[i * j] = false;
			}
			if (i < m) {
				for (int j = m * m - i - 1; j >= 0; --j) {
					ans[i + j] += ans[j];
					ans[i + j] %= MOD;
				}
			}
			res += ans[i];
			res %= MOD;
		}
	}
	cout << res << endl;
	return 0;
}