#include <vector>

using namespace std;

class HalvingEasy{
public:
    HalvingEasy(){}
    int count(vector<int> S, int T) {
        int k = 0;
        for (int i : S) {
            while (i > 0) {
                if (i == T) {
                    ++k;
                }
                i /= 2;
            }
        }
        return k;
    }
};
