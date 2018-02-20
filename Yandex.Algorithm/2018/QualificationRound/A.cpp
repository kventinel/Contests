#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	vector<bool> win(32, false);
	for (int i = 0; i < 10; ++i) {
		int a;
		cin >> a;
		win[--a] = true;
	}
	int n;
	cin >> n;
	while (n--) {
		int k = 0;
		for (int i = 0; i < 6; ++i) {
			int a;
			cin >> a;
			if (win[--a]) {
				++k;
			}
		}
		if (k >= 3) {
			cout << "Lucky\n";
		} else {
			cout << "Unlucky\n";
		}
	}
	return 0;
}
