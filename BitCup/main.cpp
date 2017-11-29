#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <thread>

typedef long long ll;
typedef long double ld;

using namespace std;

ll d_pow(ll a) {
    ll b = 1;
    for (int i = 1; i < a; ++i) {
        b *= 2;
    }
    return b;
}

unordered_map<int, vector<int>> word_to_line;
unordered_map<int, vector<int>> line_to_word;
unordered_map<string, int> word_to_int;
vector<int> word_size;
vector<string> int_to_line;
unordered_map<string, int> line_to_int;

void thread_work(vector<string> &questions, vector<string> &answers, ll l, ll r) {
    for (int ss = l; ss < r; ++ss) {
        if ((l - ss) % 100 == 0) {
            cout << (l - ss) / 100 << endl;
        }
        unordered_set<int> simple_line;
        vector<int> words;
        string word;
        string line = questions[ss];
        int line_int = line_to_int[line];
        for (const char& i : line) {
            if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9')) {
                word += i;
            } else if (!word.empty()) {
                if (word_to_int.find(word) != word_to_int.end()) {
                    int word_int = word_to_int[word];
                    words.push_back(word_int);
                    for (const int &ll : word_to_line[word_int]) {
                        if (line_int != ll) {
                            simple_line.insert(ll);
                        }
                    }
                }
                word = "";
            }
        }
        if (!word.empty()) {
            if (word_to_int.find(word) != word_to_int.end()) {
                int word_int = word_to_int[word];
                words.push_back(word_int);
                for (const int &ll : word_to_line[word_int]) {
                    if (line_int != ll) {
                        simple_line.insert(ll);
                    }
                }
            }
        }
        vector<pair<ll, int>> ans;
        std::sort(words.begin(), words.end());
        for (const int &p : simple_line) {
            vector<int> inter(words.size());
            auto end = set_intersection(words.begin(), words.end(), line_to_word[p].begin(), line_to_word[p].end(), inter.begin());
            auto beg = inter.begin();
            ll koef = d_pow(end - beg);
            while (beg != end) {
                koef += word_size[*beg];
                ++beg;
            }
            ans.push_back(make_pair(koef, p));
        }
        sort(ans.rbegin(), ans.rend());
        answers[ss] = line;
        for (int i = 0; i < min(10, (int) ans.size()); ++i) {
            answers[ss] +=  "\t" + int_to_line[ans[i].second];
        }
        auto it = line_to_word.begin();
        for (int i = ans.size(); i < 10; ++i) {
            if (it->first != line_int) {
                bool ok = true;
                for (int j = 0; j < ans.size(); ++j) {
                    if (ans[j].second == it->first) {
                        ok = false;
                    }
                }
                if (ok) {
                    answers[ss] +=  "\t" + int_to_line[it->first];
                    ++i;
                }
            }
            --i;
            ++it;
        }
    }
}

int main() {
    auto t = time(0);
    fstream fin_w("wikipedia_dump_l.tsv", ios::in);
    fstream fin_q("questions_l.tsv", ios::in);
    fstream fout("answers_ll.tsv", ios::out | ios::trunc);
    string line;
    int uu = 0;
    while (getline(fin_w, line)) {
        int uuu = rand() % 1;
        if (uuu == 0) {
            line.erase(line.size() - 1);
            line_to_int[line] = int_to_line.size();
            int line_int = int_to_line.size();
            int_to_line.push_back(line);
            vector<int> words;
            string word;
            for (char i : line) {
                if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9')) {
                    word += i;
                } else if (!word.empty()) {
                    if (word_to_int.find(word) == word_to_int.end()) {
                        word_to_int[word] = word_size.size();
                        word_size.push_back(word.size());
                    }
                    int word_int = word_to_int[word];
                    words.push_back(word_int);
                    word_to_line[word_int].push_back(line_int);
                    word = "";
                }
            }
            if (!word.empty()) {
                if (word_to_int.find(word) == word_to_int.end()) {
                    word_to_int[word] = word_size.size();
                    word_size.push_back(word.size());
                }
                int word_int = word_to_int[word];
                words.push_back(word_int);
                word_to_line[word_int].push_back(line_int);
            }
            std::sort(words.begin(), words.end());
            line_to_word[line_int] = std::move(words);
        }
    }
    vector<string> questions;
    while (getline(fin_q, line)) {
        ++uu;
        line.erase(line.size() - 1);
        questions.push_back(line);
        if (uu == 10000) {
            break;
        }
    }
    vector<string> answers(questions.size());
    vector<thread> flows;
    int n_flow = 8;
    for (int i = 0; i < n_flow; ++i) {
        std::thread temp([&answers, &questions, i, n_flow] {
            thread_work(questions, answers, i * questions.size() / n_flow, (i + 1) * questions.size() / n_flow);
        });
        flows.push_back(std::move(temp));
    }
    for (int i = 0; i < n_flow; ++i) {
        flows[i].join();
    }
    for (string s : answers) {
        fout << s << endl;
    }
    cout << time(0) - t << endl;
    return 0;
}