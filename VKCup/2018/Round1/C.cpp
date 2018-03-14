#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

using ll = long long;
using ld = long double;

struct Node {
    Node* zero;
    Node* one;
    Node* father;
    int k = 0;
};

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) {
        cin >> i;
    }
    Node* root = new Node();
    while (n--) {
        int b;
        cin >> b;
        Node* temp = root;
        int k = (1 << 29);
        while (k > 0) {
            if (temp->k == 0) {
                temp->zero = new Node();
                temp->one = new Node();
                temp->zero->father = temp;
                temp->one->father = temp;
            }
            ++temp->k;
            if (b / k == 1) {
                temp = temp->one;
            } else {
                temp = temp->zero;
            }
            b %= k;
            k >>= 1;
        }
        ++temp->k;
    }
    for (int i : a) {
        int u = 0;
        int k = (1 << 29);
        Node* temp = root;
        while (k > 0) {
            if (i / k == 1) {
                if (temp->one->k != 0) {
                    temp = temp->one;
                } else {
                    temp = temp->zero;
                    u += k;
                }
            } else {
                if (temp->zero->k != 0) {
                    temp = temp->zero;
                } else {
                    temp = temp->one;
                    u += k;
                }
            }
            i %= k;
            k /= 2;
        }
        while (temp->father != nullptr) {
            --temp->k;
            temp = temp->father;
        }
        --temp->k;
        cout << u <<  ;
    }
    cout << endl;
    return 0;
}
