#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int c;
    cin >> c;
    map<string, vector<pair<bool, string>>> ofices;
    while (c-- > 0) {
        string city;
        cin >> city;
        ofices.insert(make_pair(city,
            vector<pair<bool, string>>(24, make_pair(false, ""))));
        int n;
        cin >> n;
        while (n-- > 0) {
            string empty;
            string name;
            cin >> empty >> name;
            for (int time = 0; time < 24; ++time) {
                if (empty[time] == '.') {
                    ofices[city][time] = make_pair(true, name);
                }
            }
        }
    }
    int m;
    cin >> m;
    while (m-- > 0) {
        int n;
        cin >> n;
        std::vector<string> cities(n);
        for (int i = 0; i < n; ++i) {
            cin >> cities[i];
        }
        for (int time = 0; time < 24; ++time) {
            bool ok = true;
            for(int i = 0; i < n; ++i) {
                if (!ofices[cities[i]][time].first) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << "Yes";
                for (int i = 0; i < n; ++i) {
                    cout << " " << ofices[cities[i]][time].second;
                }
                cout << endl;
                break;
            }
            if (time == 23) {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}