#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string s;
	vector<string> tree;
	while (getline(cin, s)) {
		tree.push_back(s);
	}
	for (int i = 0; i < tree.size(); ++i) {
		if (tree[i].size() > tree[tree.size() - 2].size()) {
			cout << "NO" << endl;
			return 0;
		}
		while (tree[i].size() != tree[tree.size() - 2].size()) {
			tree[i] += ' ';
		}
	}
	// 1
	int count = 0;
	for (int i = 0; i < tree.size(); ++i) {
		for (auto c : tree[i]) {
			if (c == '*') {
				if (i != 0) {
					cout << "NO" << endl;
					return 0;
				}
				++count;
			}
		}
	}
	if (count != 1) {
		cout << "NO" << endl;
		return 0;
	}
	// 2
	count = 0;
	for (auto c : tree[0]) {
		if (c != ' ') {
			++count;
		}
	}
	if (count != 1) {
		cout << "NO" << endl;
		return 0;
	}
	// 3
	for (int i = 1; i < tree.size() - 1; ++i) {
		int old_count = count;
		count = 0;
		for (auto c : tree[i]) {
			if (c != ' ') {
				++count;
			}
		}
		if (old_count + 2 != count) {
			cout << "NO" << endl;
			return 0;
		}
	}
	// 4
	if (tree[tree.size() - 2][0] == ' ') {
		cout << "NO" << endl;
		return 0;
	}
	// 5
	count = 3;
	for (int i = 1; i < tree.size() - 1; ++i) {
		int old_count = count;
		count = 1;
		for (auto c : tree[i]) {
			if (c == 'x') {
				count = 2;
			}
		}
		if ((old_count ^ count) == 0) {
			cout << "NO" << endl;
			return 0;
		}
	}
	// 6
	for (int i = 0; i < tree.size() - 1; ++i) {
		int j = 0;
		int k = tree[i].size() - 1;
		while (j < k) {
			if (tree[i][j] != tree[i][k]) {
				cout << "NO" << endl;
				return 0;
			}
			++j;
			--k;
		}
	}
	// 7
	for (int i = 1; i < tree.size() - 1; ++i) {
		count = 1;
		for (auto c : tree[i]) {
			if (c == 'x') {
				if (count == 0) {
					cout << "NO" << endl;
					return 0;
				}
				count = 0;
			} else {
				++count;
			}
		}
	}
	// 8
	for (int i = 0; i < tree.size() - 1; ++i) {
		for (auto c : tree[i]) {
			if (c == '#') {
				cout << "NO" << endl;
				return 0;
			} 
		}
	} 
	int i = tree.size() - 1;
	int j = tree[i].size() / 2;
	int k = j;
	while (j >= 0) {
		if (tree[i][j] == '#' && tree[i][j] == '#') {
			--j;
			++k;
		} else {
			break;
		}
	}
	while (j >= 0) {
		if (tree[i][j] != ' ' || tree[i][k] != ' ') {
			cout << "NO" << endl;
			return 0;
		}
		--j;
		++k;
	}
	cout << "YES" << endl;
	return 0;
}