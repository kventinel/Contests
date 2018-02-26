#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

map<pair<string, int>, int> q;
vector<vector<int>> g;
vector<pair<string, int>> refer;
map<string, int> p;
bool True[1005];
map<string, int> ans;

int cur;

void bfs(int x) {
    True[x] = true;
    string s = refer[x].first;
    int num = refer[x].second;
    p[s] = 0;
    ans[s] = num;
    queue<pair<int, int>> q;
    q.push(make_pair(x, 0));
        int u = q.front().first;
        int depth = q.front().second;
        q.pop();
        string s = refer[u].first;
        int num = refer[u].second;
        if (u != x && ans[s] != num) {
            continue;
        }
        for (int i = 0; i < g[u].size(); ++i) {
                s = refer[g[u][i]].first;
                num = refer[g[u][i]].second;
                if (p.count(s) == 0) {
                    p[s] = depth + 1;
                    ans[s] = num;
                    q.push(make_pair(g[u][i], depth + 1));
                } else if (p[s] == depth + 1 && ans[s] < num) {
                    ans[s] = num;
                    q.push(make_pair(g[u][i], depth + 1));
                }
                True[g[u][i]] = true;
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        g.push_back(vector<int>());
    }
    refer = vector<pair<string, int>>(n);
    for (int i = 0; i < n; ++i) {
        string s;
        int num;
        cin >> s >> num;
        if (q.count(make_pair(s, num)) == 0) {
            k = cur;
            refer[cur] = make_pair(s, num);
            q[make_pair(s, num)] = cur++;
        } else {
            k = q[make_pair(s, num)];
        }
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            cin >> s >> num;
            if (q.count(make_pair(s, num)) == 0) {
                g[k].push_back(cur);
                refer[cur] = make_pair(s, num);
                q[make_pair(s, num)] = cur++;
            } else {
                g[k].push_back(q[make_pair(s, num)]);
            }
        }
        getline(cin, s);
        getline(cin, s);
    }
    bfs(0);
    cout << ans.size() - 1 << endl;
    for (auto it = ans.begin(); it != ans.end(); ++it) {
        if ((*it).first != refer[0].first) {
            cout << (*it).first <<   << (*it).second << endl;
        }
    }
    return 0;
}
