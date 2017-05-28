#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct triple {
    int w, d, l;

    triple() : w(0), d(0), l(0) {}

    bool operator<(const triple &other) const {
        if (w != other.w) {
            return w < other.w;
        }
        if (d != other.d) {
            return d < other.d;
        }
        return l < other.l;
    }
};

int main() {
    int n;
    cin >> n;
    vector<triple> ans;
    ans.push_back(triple());
    int p = 1;
    while (p < 37501) {
        p *= 2;
    }
    vector<int> tree(2 * p, -30000);
    for (int i = 0; i < n; ++i) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        int size = ans.size();
        for (int j = 0; j < size; ++j) {
            triple temp = ans[j];
            if (c == 'W') {
                temp.w -= a;
                temp.d += b;
                temp.l += b;
            } else if (c == 'D') {
                temp.w += b;
                temp.d -= a;
                temp.l += b;
            } else {
                temp.w += b;
                temp.d += b;
                temp.l -= a;
            }
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        vector<triple> temp_ans = std::move(ans);
        ans = vector<triple>();
        int it = temp_ans.size();
        while (it != 0) {
            --it;
            int w = temp_ans[it].w;
            int d = temp_ans[it].d;
            int l = temp_ans[it].l;
            if (w < -12500 || d < -12500 || l < -12500) {
                continue;
            }
            int m = -30000;
            int vert = d + 12500 + p;
            while (vert > 1) {
                if (vert % 2 != 0) {
                    m = max(m, tree[vert]);
                    ++vert;
                }
                vert /= 2;
            }
            if (m < l) {
                vert = d + 12500 + p;
                tree[vert] = l;
                ans.push_back(temp_ans[it]);
                vert /= 2;
                while (vert > 0) {
                    tree[vert] = max(tree[vert * 2],
                        tree[vert * 2 + 1]);
                    vert /= 2;
                }
            }
        }
        for (int j = 0; j < p; ++j) {
            tree[p + j] = -30000;
            tree[j] = -30000;
        }
    }
    int res = 0;
    for (int i = 0; i < ans.size(); ++i) {
        res = max(res, min(ans[i].w, min(ans[i].l, ans[i].d)));
    }
    cout << res << endl;
    return 0;
}