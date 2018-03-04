#include <iostream>

using namespace std;

typedef long long ll;

ll get_sum(ll num) {
	ll sum = 0;
	while (num > 0) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

int main() {
	for (ll i = 10, k = 0; k < 18; ++i) {
		ll sum = get_sum(i);
		if (sum == 1) {
			continue;
		}
		ll temp = sum;
		while (sum < i) {
			sum *= temp;
		}
		if (sum == i) {
			++k;
			cout << k << " " << i << endl;
		}
	}
}