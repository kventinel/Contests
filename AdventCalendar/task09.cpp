#include <iostream>
#include <vector>

using namespace std;

int permutation(vector<int>& numbers, vector<int>& permutation_data) {
	if (numbers.size() == 0) {
		int temp = -100;
		for (int i = 1; i < permutation_data.size(); ++i) {
			if (permutation_data[i - 1] * permutation_data[i] < temp) {
				return 0;
			}
			temp = permutation_data[i - 1] * permutation_data[i];
		}
		return 1;
	} 
	int ans = 0;
	for (int i = 0; i < numbers.size(); ++i) {
		int temp = numbers[i];
		numbers.erase(numbers.begin() + i);
		permutation_data.push_back(temp);
		ans += permutation(numbers, permutation_data);
		permutation_data.erase(--permutation_data.end());
		numbers.insert(numbers.begin() + i, temp);
	}
	return ans;
} 

int main() {
	vector<int> numbers{-3, -2, -1, 0, 1, 2, 3, 4, 5, 6};
	vector<int> permutation_data;
	cout << permutation(numbers, permutation_data) << endl;
}