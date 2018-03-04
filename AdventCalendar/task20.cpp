#include <iostream>
#include <vector>

using namespace std;

typedef long double ld;

int main() {
	vector<vector<ld> > v(395, vector<ld> (201));
	v[0][200] = 1;
	for (int i = 0; i < 394; ++i) {
		for (int j = 1; j <= 200; ++j) {
			v[i + 1][j - 1] += v[i][j] / 2;
			v[i + 1][j] += v[i][j] / 2;
		}
	}
	std::cout << v[394][1] << std::endl;
}