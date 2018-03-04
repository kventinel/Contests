#include <iostream>

using namespace std;

int main() {
	long double o = 0.5;
	long double r = 0.5;
	long double ans = 0;
	for (int i = 0; i < 1000000; ++i) {
		ans += r * 0.5 * (i + 2);
		long double to = o * 0.5;
		long double tr = o * 0.5 + r * 0.5;
		o = to;
		r = tr;
	}
	cout << ans << endl;
}