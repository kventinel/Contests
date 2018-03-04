#include <iostream>
#include <vector>

using namespace std;

typedef long double ld;

int main() {
	const int size = 10000000;
	const int iters = 300;
	vector<ld> probs(size);
	probs[0] = 1;
	ld ans = 0;
	for (int it = 0; it < iters; ++it) {
		ld add = 0;
		for (int s = 0; s < size; ++s) {
			ans += probs[s] * s * (it + 1) / size;
			add += probs[s] / size;
			probs[s] = add;
		}
	}
	cout << ans << endl;
}