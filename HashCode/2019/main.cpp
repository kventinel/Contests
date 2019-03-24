#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <utility>
#include <cassert>
#include <random>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <ctime>
#include <unordered_map>
#include <unordered_set>

#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

mt19937 gen(time(nullptr));

map<string, int> mptags;
int mpit;
inline int get_tag(const string& s) {
    int& rf = mptags[s];
    if (rf == 0)
        rf = ++mpit;
    return rf - 1;
}

struct Photo {
    int id;
    bool vert;
    unordered_set<int> tags;
};

vector<Photo> read_data(istream& in) {
    vector<Photo> data;
    int n;
    in >> n;
    for (int i = 0; i < n; ++i) {
        char orient;
        int m;
        in >> orient >> m;
        Photo photo;
        photo.id = i;
        photo.vert = (orient == 'V');
        string s;
        for (int i = 0; i < m; ++i) {
            in >> s;
            photo.tags.insert(get_tag(s));
        }
        data.push_back(photo);
    }
    return data;
}

void print_ans(ostream& out, vector<pii> ans) {
    out << ans.size() << "\n";
    for (const pii& p : ans) {
        out << p.first;
        if (p.second != -1)
            out << ' ' << p.second;
        out << "\n";
    }
    out.flush();
}

vector<pii> read_ans_from_file(istream& in) {
    vector<pii> res;
    int n;
    in >> n;
    stringstream ss;
    string s;
    getline(in, s);
    for (int i = 0; i < n; ++i) {
        int x = -1, y = -1;
        getline(in, s);
        ss.clear();
        ss << s;
        ss >> x >> y;
        res.emplace_back(x, y);
    }
    return res;
}

vector<pii> stupid_random(vector<Photo> data, bool mix_last = true) {
    vector<Photo> hor, ver;
    for (size_t i = 0; i < data.size(); ++i)
        (data[i].vert ? ver : hor).push_back(data[i]);

    for (size_t i = 0; i < hor.size(); ++i)
        swap(hor[i], hor[uniform_int_distribution<>(0, i)(gen)]);
    for (size_t i = 0; i < ver.size(); ++i)
        swap(ver[i], ver[uniform_int_distribution<>(0, i)(gen)]);

    vector<pii> ans;
    for (size_t i = 0; i < hor.size(); ++i)
        ans.push_back(make_pair(hor[i].id, -1));
    for (size_t i = 0; i + 1 < ver.size(); i += 2)
        ans.push_back(make_pair(ver[i].id, ver[i + 1].id));

    if (mix_last) {
        for (size_t i = 0; i < ans.size(); ++i)
            swap(ans[i], ans[uniform_int_distribution<>(0, i)(gen)]);
    }
    return ans;
}

vector<pii> solve_e(vector<Photo> data) {
    size_t n = data.size();
    vector<pair<bitset<500>, int>> v;
    for (size_t i = 0; i < n; ++i) {
        bitset<500> cur;
        for (int x : data[i].tags)
            cur.set(x);
        v.emplace_back(cur, data[i].id);
    }
    cout << n << endl;
    cout << v.size() << endl;

    vector<pii> ans;
    set<int> st;
    for (int i = 2; i < n; ++i)
        st.insert(i);
    int iter = 0;
    vector<int> temp(n);
    temp[0] = v[0].second;
    temp[n - 1] = v[1].second;
    while (st.size() > 0) {
        if (iter % 1000 == 0) cerr << "Solve E: " << iter << " " << st.size() << endl;

        int cur = *st.begin();
        st.erase(cur);
        int bst = -1, bsti = -1;
        for (int x : st) {
            int common = (v[cur].first & v[x].first).count();
            if (common > bst)
                bst = common, bsti = x;
        }
        temp[iter * 2 + 1] = v[cur].second;
        temp[iter * 2 + 2] = v[bsti].second;
        st.erase(bsti);
        ++iter;
    }
    for (int i = 0; i < n; i += 2) {
        ans.emplace_back(temp[i], temp[i + 1]);
    }
    return ans;
}

vector<pii> solve_d(vector<Photo> data) {
    size_t n = data.size();
    vector<pair<bitset<220>, int>> v(n);
    int a = 0;
    int b = 60000;
    for (size_t i = 0; i < n; ++i) {
        bitset<220> cur;
        for (int x : data[i].tags)
            cur.set(x);
        if (data[i].vert) {
            v[a].first = cur;
            v[a].second = data[i].id;
            ++a;
        } else {
            v[b].first = cur;
            v[b].second = data[i].id;
            ++b;
        }
    }
    cout << n << endl;
    cout << v.size() << endl;

    vector<pii> ans(60000);
    set<int> st;
    for (int i = 2; i < 60000; ++i)
        st.insert(i);
    int iter = 0;
    vector<int> temp;
    for (int i = 60000; i < n; ++i) {
        if (iter % 1000 == 0) cerr << "Solve E: " << i << endl;

        int cur = i;
        int bst = -1, bsti = -1;
        for (int x : st) {
            int common = (v[cur].first & v[x].first).count();
            if (common > bst)
                bst = common, bsti = x;
        }
        temp.push_back(v[cur].second);
        temp.push_back(v[bsti].second);
        st.erase(bsti);
        bst = -1;
        bsti = -1;
        for (int x : st) {
            int common = (v[cur].first & v[x].first).count();
            if (common > bst)
                bst = common, bsti = x;
        }
        temp.push_back(v[bsti].second);
        st.erase(bsti);
        ++iter;
    }
    for (int i = 0; i < 30000; ++i) {
        ans[2 * i].first = temp[3 * i];
        ans[2 * i].second = -1;
    }
    for (int i = 0; i < 30000; ++i) {
        ans[2 * i + 1].first = temp[3 * i + 1];
    }
    for (int i = 1; i < 30000; ++i) {
        ans[2 * i - 1].second = temp[3 * i + 2];
    }
    ans[1].second = temp[2];
    return ans;
}

unordered_set<int> intersection(const unordered_set<int> &a, const unordered_set<int> &b) {
    unordered_set<int> answer;
    for (int i : a) {
        if (b.find(i) != b.end()) {
            answer.insert(i);
        }
    }
    return answer;
}

unordered_set<int> make_set_for_pair(const vector<Photo> &data, pii a) {
    unordered_set<int> now;
    for (int s : data[a.first].tags) {
        now.insert(s);
    }
    if (a.second != -1) {
        for (int s : data[a.second].tags) {
            now.insert(s);
        }
    }
    return now;
}

int get_score(const vector<pii> &answer, const vector<Photo> &data) {
    int res = 0;
    unordered_set<int> prev;
    int i = 0;
    vector<int> ans(answer.size());
    while (i < answer.size()) {
        unordered_set<int> now = make_set_for_pair(data, answer[i]);
        int inter_size = intersection(prev, now).size();
        res += min(inter_size, (int) min(prev.size() - inter_size, now.size() - inter_size));
        prev = move(now);
        ++i;
    }
    return res;
}

int get_pair_score(const vector<Photo> &data, pii a, pii b) {
    unordered_set<int> left = make_set_for_pair(data, a);
    unordered_set<int> right = make_set_for_pair(data, b);
    int inter_size = intersection(left, right).size();
    return min(inter_size, (int) min(left.size() - inter_size, right.size() - inter_size));
}

int get_pair_score(const vector<Photo> &data, pii a, pii b, pii c) {
    return get_pair_score(data, a, b) - get_pair_score(data, a, c);
}

int get_score_for_index(const vector<Photo> &data, const vector<pii> &ans, int idx) {
    int a = 0;
    if (idx > 0) {
        a += get_pair_score(data, ans[idx], ans[idx - 1]);
    }
    if (idx + 1 < ans.size()) {
        a += get_pair_score(data, ans[idx], ans[idx + 1]);
    }
    return a;
}

int try_swaps(const vector<Photo>& data, vector<pii>& ans) {
    int n = (int)ans.size();
    int idx1 = uniform_int_distribution<>(0, n - 1)(gen);
    int idx2 = uniform_int_distribution<>(0, n - 2)(gen);
    if (idx2 >= idx1)
        ++idx2;
    int prev = 0;
    if (idx1 > 0) {
        prev += get_pair_score(data, ans[idx1 - 1], ans[idx1], ans[idx2]);
    }
    if (idx1 + 1 < n) {
        prev += get_pair_score(data, ans[idx1 + 1], ans[idx1], ans[idx2]);
    }
    if (idx2 > 0) {
        prev += get_pair_score(data, ans[idx2 - 1], ans[idx2], ans[idx1]);
    }
    if (idx2 + 1 < n) {
        prev += get_pair_score(data, ans[idx2 + 1], ans[idx2], ans[idx1]);
    }
    if (prev < 0) {
        swap(ans[idx1], ans[idx2]);
        return -prev;
    }
    if (idx1 > 0 && idx1 + 2 < n) {
        prev = get_pair_score(data, ans[idx1 - 1], ans[idx1], ans[idx1 + 1]);
        prev += get_pair_score(data, ans[idx1 + 2], ans[idx1 + 1], ans[idx1]);
        if (prev < 0) {
            swap(ans[idx1], ans[idx1 + 1]);
            return -prev;
        }
    }

    if (ans[idx1].second != -1 && ans[idx2].second != -1) {
        prev = get_score_for_index(data, ans, idx1);
        prev += get_score_for_index(data, ans, idx2);
        swap(ans[idx1].second, ans[idx2].second);
        int next = get_score_for_index(data, ans, idx1);
        next += get_score_for_index(data, ans, idx2);
        if (next > prev) {
            return next - prev;
        }
        swap(ans[idx1].first, ans[idx2].first);
        swap(ans[idx1].second, ans[idx2].second);
        next = get_score_for_index(data, ans, idx1);
        next += get_score_for_index(data, ans, idx2);
        if (next > prev) {
            return next - prev;
        }
        swap(ans[idx1].first, ans[idx2].first);
    }
    return 0;
}


int main(int argc, char **argv) {
    string filename = "d_in.txt";
    if (argc > 1)
        filename = argv[1];
    ifstream fin(filename);
    ofstream fout(filename + ".out");
    ifstream ans_file("ans_file");
    vector<Photo> data = read_data(fin);

    //vector<pii> ans = stupid_random(data);
    vector<pii> ans = solve_d(data);
    int score = get_score(ans, data);
    for (int i = 0; i < 0; ++i) {
        //if ()
        score += try_swaps(data, ans);
        cout << i << " " << score << endl;
        //cerr << i << "\t" << get_score(ans, data) << endl;
    }
    print_ans(fout, ans);
    cout << get_score(ans, data) << endl;
    /*int temp = 0;
    for (int i = 1; i < ans.size(); ++i) {
        temp += get_pair_score(data, ans[i - 1], ans[i]);
    }
    cout << temp << endl;*/
}

/**
a_example.txt 6
b_lovely_landscapes.txt 840000
c_memorable_moments.txt 2166
d_pet_pictures.txt 220
e_shiny_selfies.txt 500
*/