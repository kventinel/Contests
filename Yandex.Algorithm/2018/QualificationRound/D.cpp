#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll MOD = 1000000007;

struct query{
	int l, r, i, a, b, c;
};

bool cmp1(const query &a, const query &b) {
	if (a.l != b.l) {
		return a.l < b.l;
	}
	return a.r < b.r;
}

bool cmp2(const query &a, const query& b) {
	return a.i < b.i;
}

bool triangle(vector<pair<ll, int>> &v) {
	sort(v.begin(), v.end());
	for (int i = 2; i < v.size(); ++i) {
		if (v[i - 1].first + v[i - 2].first > v[i].first) {
			v = {v[i - 2], v[i - 1], v[i]};
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<ll> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	vector<query> w(m);
	for (int i = 0; i < m; ++i) {
		cin >> w[i].l >> w[i].r;
		--w[i].l;
		--w[i].r;
		w[i].i = i;
	}
	sort(w.begin(), w.end(), cmp1);
	set<pair<ll, int>> s;
	int first = 0;
	int j = 0;
	for (int i = 0; i < n; ++i) {
		s.insert(make_pair(v[i], i));
		vector<pair<ll, int>> temp;
		auto it = s.find(make_pair(v[i], i));
		int k = 0;
		while (it != s.begin() && k < 3) {
			++k;
			temp.push_back(*it);
            --it;
		}
		if (k < 3) {
			temp.push_back(*it);
		}
		k = 0;
		it = s.find(make_pair(v[i], i));
		++it;
		while (it != s.end() && k < 2) {
			temp.push_back(*it);
			++it;
			++k;
		}
		if (triangle(temp)) {
			while (true) {
				while (j < m && w[j].l == first) {
					if (w[j].r < i) {
						w[j].a = -1;
					} else {
						w[j].a = temp[0].second;
						w[j].b = temp[1].second;
						w[j].c = temp[2].second;
					}
					++j;
				}
				if (j == m) {
					break;
				}
				if (v[first] < temp[0].first || v[first] > temp[2].first) {
					s.erase(s.find(make_pair(v[first], first)));
					++first;
				} else {
					it = s.find(make_pair(v[first], first));
					temp.clear();
					k = 0;
					if (it != s.begin()) {
						--it;
						while (it != s.begin() && k < 4) {
							++k;
							temp.push_back(*it);
							--it;
						}
						if (k < 4) {
							temp.push_back(*it);
						}
					}
					k = 0;
					it = s.find(make_pair(v[first], first));
					++it;
					while (it != s.end() && k < 4) {
						temp.push_back(*it);
						++it;
						++k;
					}
					s.erase(s.find(make_pair(v[first], first)));
					++first;
					if (!triangle(temp)) {
						break;
					}
				}
			}
		}
		while (j < m && w[j].l == first && w[j].r <= i) {
			w[j].a = -1;
			++j;
		}
		if (j == m) {
			break;
		}
	}
    while (j < m) {
        w[j].a = -1;
        ++j;
    }
	sort(w.begin(), w.end(), cmp2);
	for (auto &a : w) {
		if (a.a == -1) {
			cout << -1 << endl;
		} else {
			cout << a.a  + 1 << " " << a.b + 1 << " " << a.c + 1 << endl;
		}
	}
	return 0;
}
