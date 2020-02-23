#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdio>


using namespace std;

using ll = long long;


struct lib {
    vector<int> book;
    int T;
    int M;
};


vector<int> S;
vector<lib> lb;


string ifile(string c) {
    switch(c[0]) {
        case 'A':
            return "a_example.txt";
        case 'B':
            return "b_read_on.txt";
        case 'C':
            return "c_incunabula.txt";
        case 'D':
            return "d_tough_choices.txt";
        case 'E':
            return "e_so_many_books.txt";
        case 'F':
            return "f_libraries_of_the_world.txt";
    }
    return "";
}


string ofile(string c) {
    return c + ".txt";
}


bool cmp(int a, int b) {
    return S[a] > S[b];
}

bool cmp2(int a, int b) {
    return lb[a].M > lb[b].M;
}

bool cmp3(int a, int b) {
    return lb[a].M * lb[b].T > lb[b].M * lb[a].T;
}


ll score(const vector<lib> &lb, int D, const vector<int> &order) {
    unordered_set<int> books;
    int day = 0;
    ll s = 0;
    for (int i = 0; i < (int) lb.size(); ++i) {
        const lib &ii = lb[order[i]];
        day += ii.T;
        if (day > D) {
            break;
        }
        int d2 = day;
        for (int j = 0; j < (int) ii.book.size(); j += ii.M) {
            ++d2;
            if (d2 > D) {
                break;
            }
            for (int k = j; k < min((int) ii.book.size(), j + ii.M); ++k) {
                books.insert(ii.book[k]);
            }
        }
    }
    for (int book : books) {
        s += S[book];
    }
    return s;
}


void swap_books(vector<lib> &lb, int D, const vector<int> &order) {
    unordered_set<int> books;
    int day = 0;
    for (int i = 0; i < (int) lb.size(); ++i) {
        lib &ii = lb[order[i]];
        day += ii.T;
        if (day > D) {
            break;
        }
        int d2 = day;
        vector<int> used;
        vector<int> unused;
        for (int j : ii.book) {
            if (books.find(j) != books.end()) {
                used.push_back(j);
            } else {
                unused.push_back(j);
            }
        }
        for (int j = 0; j < (int) unused.size(); ++j) {
            ii.book[j] = unused[j];
        }
        int p = unused.size();
        for (int j = 0; j < (int) used.size(); ++j) {
            ii.book[j + p] = used[j];
        }
        for (int j = 0; j < D; ++j) {
            ++d2;
            if (d2 > D) {
                break;
            }
            for (int k = j; k < min((int) ii.book.size(), j + ii.M); ++k) {
                books.insert(ii.book[k]);
            }
        }
    }
}

int main(int argc, char* argv[]) {
    string task = "";
    task += argv[1][0];
    freopen(ifile(task).c_str(), "r", stdin);

    /// INPUT

    int B, L, D;
    cin >> B >> L >> D;
    S.resize(B);
    for (int &i : S) {
        cin >> i;
    }
    lb.resize(L);
    for (int i = 0; i < L; ++i) {
        int N;
        cin >> N >> lb[i].T >> lb[i].M;
        lb[i].book.resize(N);
        for (int j = 0; j < N; ++j) {
            cin >> lb[i].book[j];
        }
        sort(lb[i].book.begin(), lb[i].book.end(), cmp);
    }

    vector<int> order(L);
    for (int i = 0; i < L; ++i) {
        order[i] = i;
    }
    sort(order.begin(), order.end(), cmp3);
    swap_books(lb, D, order);

    /// SCORE

    cout << task << ": " << score(lb, D, order) << endl;


    /// OUTPUT

    freopen(ofile(task).c_str(), "w", stdout);
    cout << L << endl;
    for (int j = 0; j < L; ++j) {
        int i = order[j];
        cout << i << " " << lb[i].book.size() << endl;
        for (int j : lb[i].book) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
