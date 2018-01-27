#include <vector>
using namespace std;

class IncreasingSequencesEasy{
public:
    int count(vector<int> L, vector<int> R) {
        vector<int> v(10001);
        v[0] = 1;
        for (int i = 0; i < L.size(); ++i) {
            vector<int> temp(10001);
            int sum = 0;
            for (int j = 0; j <= 10000; ++j) {
                if (L[i] <= j && j <= R[i]) {
                    temp[j] = sum;
                }
                sum += v[j];
                sum %= 998244353;
            }
            v = std::move(temp);
        }
        int sum = 0;
        for (int i = 0; i <= 10000; ++i) {
            sum += v[i];
            sum %= 998244353;
        }
        return sum;
    }
};
