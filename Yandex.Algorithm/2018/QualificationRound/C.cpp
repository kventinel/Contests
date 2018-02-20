#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll MOD = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll ans = 1;
	for (int i = 0; i < (n - 1) * (n - 1); ++i) {
		ans *= n;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}
