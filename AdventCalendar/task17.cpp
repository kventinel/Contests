#include <iostream>
#include <vector>

const int MAX = 1000000;

using namespace std;

int main() {
	vector<int> eratosfen(MAX, true);
	vector<int> simple;
	for (int i = 2; i < MAX; ++i) {
		if (eratosfen[i]) {
			simple.push_back(i);
			for (int j = 2 * i; j < MAX; j += i) {
				eratosfen[j] = false;
			}
		}
	}
	vector<int> ans;
	int k = 0;
	for (int i = 0; i < simple.size(); ++i) {
		int j = i + 1;
		int sum = simple[i];
		int new_k = 1;
		while (sum < MAX && j <= simple.size()) {
			if (eratosfen[sum]) {
				if (k == new_k) {
					ans.push_back(sum);
				} else if (k < new_k) {
					ans.clear();
					ans.push_back(sum);
					k = new_k;
				}
			}
			if (j < simple.size()) {
				sum += simple[j];
			}
			++j;
			++new_k;
		}
	}
	cout << k << endl;
	for (int a : ans) {
		cout << " " << a;
	}
	cout << endl;
}