#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll sum_digits(ll number) {
	ll sum = 0;
	while (number > 0) {
		sum += number % 10;
		number /= 10;
	}
	return sum;
}

int main() {
	vector<vector<ll>> v(19, vector<ll> (1000));
	for (int i = 0; i < 1000; ++i) {
		if (sum_digits(i) < 10 && i > 99) {
			v[3][i] = 1;
		}
	}
	for (int i = 4; i < 19; ++i) {
		for (int j = 0; j < 1000; ++j) {
			for (int k = 0; k < 10; ++k) {
				if (sum_digits((j * 10 + k) % 1000) < 10) {
					v[i][(j * 10 + k) % 1000] += v[i - 1][j];
				}
			}
		}
	}
	ll sum = 0;
	for (int i = 0; i < 1000; ++i) {
		sum += v[18][i];
	}
	cout << sum << endl;
	return 0;
}