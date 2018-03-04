#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef __int128_t ii;

ll MAX = 0;

ll rek(vector<ii>::iterator begin, vector<ii>::iterator end, ii temp, int k) {
	ll res = k % 2 == 0 ? MAX / temp : -MAX / temp;
	while (begin != end) {
		if (temp * (*begin) < MAX) {
			res += rek(begin + 1, end, temp * (*begin), k + 1);
			++begin;
		} else {
			break;
		}
	}
	return res;
}

int main() {
	ll n = 1;
	for (int i = 0; i < 25; ++i) {
		n *= 2;
	}
	MAX = n * n;
	vector<bool> eratosfen(n);
	vector<ii> simple;
	for (ll i = 2; i < n; ++i) {
		if (!eratosfen[i]) {
			simple.push_back(i * i);
		}
		for (ll j = i * 2; j < n; j += i) {
			eratosfen[j] = true;
		}
	}
	cout << rek(simple.begin(), simple.end(), 1, 0) << endl;
}