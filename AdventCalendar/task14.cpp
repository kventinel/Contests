#include <iostream>
#include <cmath>

using namespace std;

typedef __int128_t ll;
typedef long double	 ld;

int main() {
	for (ll i = 1000000000000; ; ++i) {
		ll temp = i / sqrt(2);
		if (i * (i - 1) == (temp - 1) * (temp - 2) * 2) {
			cout << (long long) i << endl;
			return 0;
		}
		if (i * (i - 1) == temp * (temp - 1) * 2) {
			cout << (long long) i << endl;
			return 0;
		}
		if (i * (i - 1) == temp * (temp + 1) * 2) {
			cout << (long long) i << endl;
			return 0;
		}
		if (i * (i - 1) == (temp + 1) * (temp + 2) * 2) {
			cout << (long long) i << endl;
			return 0;
		}
	}
}