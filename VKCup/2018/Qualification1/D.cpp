#include <bits/stdc++.h>

using namespace std;

struct Node {
    vector<Node*> sons = vector<Node*>(26, nullptr);
    Node* father = nullptr;
    int count = 0;
    bool end = false;
};

int main() {
    ios_base::sync_with_stdio(false);
    Node* root = new Node();
    string s;
    int ans = 0;
    while(getline(cin, s)) {
        Node* temp = root;
        int m = 0;
        s += ' ';  
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                ++ans;
                if (temp->sons[c - 'a'] == nullptr) {
                    if (m > 1 && temp->end) {
                        ans -= m - 2;
                    }
                    temp->sons[c - 'a'] = new Node();
                    temp->sons[c - 'a']->father = temp;
                    m = 0;
                }
                temp = temp->sons[c - 'a'];
                ++(temp->count);
                if (temp->count == 2) {
                    ++m;
                }
            } else {
                if (temp->end) {
                    if (m > 1) {
                        ans -= m - 2;
                    }
                    while (temp != root) {
                        --(temp->count);
                        temp = temp->father;
                    }
                } else {
                    temp->end = true;
                    temp = root;
                }
                ++ans;
                m = 0;
            }
        }
    }
    cout << ans << endl;
}
