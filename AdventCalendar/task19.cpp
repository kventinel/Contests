#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	ll MAX = 1000000;
	MAX *= MAX;
	ll a = 1;
	ll k = 0;
	for (ll i = MAX; i > 0; --i) {
		ll j = i;
		while (j % 5 == 0) {
			j /= 5;
			++k;
		}
		while (k > 0 && j % 2 == 0) {
			--k;
			j /= 2;
		}
		a *= j;
		a %= 100000;
	}
	cout << a << endl;
}