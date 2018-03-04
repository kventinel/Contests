#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> bits(10);
	bits[0] = 1;
	for (int i = 1; i < 10; ++i) {
		bits[i] = bits[i - 1] * 2;
	}
	long long m = 100000;
	m *= 100000;
	vector<bool> v(m, true);
	vector<int> ans(bits[9]);
	ans[0] = 1;
	int k = 0;
	for (long long i = 2; i < m; ++i) {
		if (v[i]) {
			for (long long j = 2; i * j < m; ++j) {
				v[i * j] = false;
			}
			long long u = i;
			int temp = 0;
			while (u > 0) {
				if (u % 10 != 0) {
					if ((temp & bits[u % 10 - 1]) == 0) {
						temp |= bits[u % 10 - 1];
					} else {
						break;
					}
				} else {
					break;
				}
				u /= 10;
			}
			if (u == 0) {
				++k;
				for (int j = 0; j < bits[9]; ++j) {
					if ((j & temp) == 0) {
						ans[j | temp] += ans[j];
					}
				}
			}
		}
	}
	cout << k << endl;
	cout << ans[bits[9] - 1] << endl;
	return 0;
}