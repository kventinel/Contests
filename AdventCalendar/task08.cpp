#include <iostream>
#include <vector>
#include <set>

using namespace std;

int gcd(int a, int b) {
	while (a && b) {
		if (a > b) {
			a %= b;
		} else {
			b %= a;
		}
	}
	return a + b;
}

int main() {
	vector<long long> simple;
	int n = 10;
	long long a = 1;
	for (int i = 0; i < n; ++i) {
		long long b = 1;
		for (int j = 0; j < n; ++j) {
			simple.push_back(a * b);
			b *= 5;
		}
		a *= 2;
	}
	long long ans = 0;
	long long MAX = 10;
	for (int iter = 0; iter < 9; ++iter) {
		for (int i = 0; i < simple.size(); ++i) {
			for (int j = i; j < simple.size(); ++j) {
				if (gcd(simple[i], simple[j]) == 1) {
					if (MAX * (simple[i] + simple[j]) % (simple[i] * simple[j]) == 0) {
						if (iter == 0) {
							cout << simple[i] << " " << simple[j] << endl;	
						}
						a = MAX * (simple[i] + simple[j]) / simple[i] / simple[j];
						vector<int> factorize;
						for (int k = 2; k * k <= a; ++k) {
							while (a % k == 0) {
								factorize.push_back(k);
								a /= k;
							}
						}
						if (a != 1) {
							factorize.push_back(a);
						}
						set<int> delimeters;
						delimeters.insert(1);
						for (int k : factorize) {
							set<int> temp;
							for (int it : delimeters) {
								temp.insert(it * k);
							}
							for (int it : temp) {
								delimeters.insert(it);
							}
						}
						if (iter == 0) {
							cout << delimeters.size() << endl;
						}
						ans += delimeters.size();
					}
				}
			}
		}
		cout << ans << endl;
		MAX *= 10;
	}
}