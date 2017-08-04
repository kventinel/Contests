#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>

using namespace std;

const int MAX = 1000000;

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> edges(n);
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        edges[a].push_back(make_pair(b, c));
        edges[b].push_back(make_pair(a, c));
    }
    vector<int> mark(n, -1);
    vector<int> ancestor(n, -2);
    stack<int> s;
    s.push(0);
    mark[0] = 0;
    ancestor[0] = -1;
    vector<int> cycle;
    while (!s.empty()) {
        int i = s.top();
        s.pop();
        if (mark[i] == edges[i].size()) {
            mark[i] = MAX;
        } else if (mark[edges[i][mark[i]].first] == -1) {
            s.push(i);
            s.push(edges[i][mark[i]].first);
            ++mark[i];
            mark[edges[i][mark[i]].first] = 0;
            ancestor[edges[i][mark[i]].first] = i;
        } else if (mark[edges[i][mark[i]].first] == MAX) {
            int temp = edges[i][mark[i]].first;
            while (mark[temp] == MAX) {
                cycle.push_back(temp);
                temp = ancestor[temp];
            }
            cycle.push_back(temp);
            stack<int> s_temp;
            s_temp.push(i);
            while (mark[s.top()] != temp) {
                s_temp.push(s.top());
                s.pop();
            }
            while (!s_temp.empty()) {
                cycle.push_back(s_temp.top());
                s_temp.pop();
            }
            break;
        } else {
            int temp = edges[i][mark[i]].first;
            cycle.push_back(i);
            while (s.top() != temp) {
                cycle.push_back(s.top());
                s.pop();
            }
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        mark[i] = 0;
    }
    vector<int> max_len(cycle.size());
    vector<int64_t> dist(cycle.size());
    for (int i = 0; i < cycle.size(); ++i) {
        for (int j = 0; j < edges[cycle[i]].size(); ++j) {
            if (edges[cycle[i]][j].first == cycle[(i + 1) % cycle.size()]) {
                dist[i] = edges[cycle[i]][j].second;
            } else {
                queue<pair<int, int64_t>> q;
                q.push(edges[cycle[i]][j]);
                mark[cycle[i]] = 1;
                while (!q.empty()) {
                    pair<int, int64_t> temp = q.front();
                    q.pop();
                    max_len[i] = max(max_len[i], temp.second);
                    for (int j = 0; j < edges[temp.first].size(); ++j) {
                        if (mark[edges[temp.first][j].first] == 0) {
                            q.push(make_pair(edges[temp.first][j].first, temp.second + edges[temp.first][j].second));
                        }
                    }
                }
            }
        }
    }
    set<int64_t> left;
    set<int64_t> right;
    int64_t add_left = 0;
    int64_t add_right = 0;
    int64_t left_i = 0;
    int64_t right_i = cycle.size() - 1;
    int64_t ans = INT64_MAX;
    for (int i = 0; i < cycle.size(); ++i) {
        int64_t left_max = max_len[left_i];
        int64_t right_max = max_len[right_i];
        if (!left.empty()) {
            left_max = max(left_max, *(--left.end()) + add_left);
        }
        if (!right.empty()) {
            right_max = max(right_max, *(--right.end()) + add_right);
        }
        if (left_max < right_max) {
            if (left_i != 0) {
                add_left += dist[left_i - 1];
            }
            left.insert(max_len[left_i] - add_left);
            ++left_i;
        } else {
            if (right_i != cycle.size() - 1) {
                add_right += dist[right_i];
            }
            right.insert(max_len[right_i] - add_right);
            ++right_i;
        }
    }
    int64_t rem_left = 0;
    int64_t rem_right = 0;
    for (int i = 0; i + 1 < cycle.size(); ++i) {
        ans = min(ans, min(*(--left.end()), *(--right.end())) + dist[left_i - 1]);
        
    }
    return 0;
}