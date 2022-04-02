#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'closestStraightCity' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY c
 *  2. INTEGER_ARRAY x
 *  3. INTEGER_ARRAY y
 *  4. STRING_ARRAY q
 */

struct trp {
  int x, y;

  string c;
};

bool cmpx(const trp &a, const trp &b) {
  if (a.x != b.x) {
    return a.x < b.x;
  }
  return a.y < b.y;
}

bool cmpy(const trp &a, const trp &b) {
  if (a.y != b.y) {
    return a.y < b.y;
  }
  return a.x < b.x;
}

int compare(const trp &a, const trp &b) {
  if (a.x != b.x && a.y != b.y) {
    return INT32_MAX;
  }
  return abs(a.x - b.x) + abs(a.y - b.y);
}

vector<string> closestStraightCity(vector<string> c, vector<int> x, vector<int> y, vector<string> q) {
  int n = c.size();
  int m = q.size();
  vector<trp> v(n);
  unordered_map<string, string> near;
  unordered_map<string, int> dist;
  for (int i = 0; i < n; ++i) {
    v[i].x = x[i];
    v[i].y = y[i];
    v[i].c = c[i];
    near[c[i]] = "";
    dist[c[i]] = INT32_MAX;
  }
  
  sort(v.begin(), v.end(), cmpx);
  for (int i = 0; i < n; ++i) {
    if (i != 0) {
      int d = compare(v[i - 1], v[i]);
      if (d < dist[v[i].c] || (d == dist[v[i].c] && v[i - 1].c < near[v[i].c])) {
        dist[v[i].c] = d;
        near[v[i].c] = v[i - 1].c;
      }
    }
    if (i + 1 < n) {
      int d = compare(v[i + 1], v[i]);
      if (d < dist[v[i].c] || (d == dist[v[i].c] && v[i + 1].c < near[v[i].c])) {
        dist[v[i].c] = d;
        near[v[i].c] = v[i + 1].c;
      }
    }
  }
  sort(v.begin(), v.end(), cmpy);
  for (int i = 0; i < n; ++i) {
    if (i != 0) {
      int d = compare(v[i - 1], v[i]);
      if (d < dist[v[i].c] || (d == dist[v[i].c] && v[i - 1].c < near[v[i].c])) {
        dist[v[i].c] = d;
        near[v[i].c] = v[i - 1].c;
      }
    }
    if (i + 1 < n) {
      int d = compare(v[i + 1], v[i]);
      if (d < dist[v[i].c] || (d == dist[v[i].c] && v[i + 1].c < near[v[i].c])) {
        dist[v[i].c] = d;
        near[v[i].c] = v[i + 1].c;
      }
    }
  }
  vector<string> answer(m);
  for (int i = 0; i < m; ++i) {
    if (near[q[i]] == "") {
      answer[i] = "NONE";
    } else {
      answer[i] = near[q[i]];
    }
  }
  return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string c_count_temp;
    getline(cin, c_count_temp);

    int c_count = stoi(ltrim(rtrim(c_count_temp)));

    vector<string> c(c_count);

    for (int i = 0; i < c_count; i++) {
        string c_item;
        getline(cin, c_item);

        c[i] = c_item;
    }

    string x_count_temp;
    getline(cin, x_count_temp);

    int x_count = stoi(ltrim(rtrim(x_count_temp)));

    vector<int> x(x_count);

    for (int i = 0; i < x_count; i++) {
        string x_item_temp;
        getline(cin, x_item_temp);

        int x_item = stoi(ltrim(rtrim(x_item_temp)));

        x[i] = x_item;
    }

    string y_count_temp;
    getline(cin, y_count_temp);

    int y_count = stoi(ltrim(rtrim(y_count_temp)));

    vector<int> y(y_count);

    for (int i = 0; i < y_count; i++) {
        string y_item_temp;
        getline(cin, y_item_temp);

        int y_item = stoi(ltrim(rtrim(y_item_temp)));

        y[i] = y_item;
    }

    string q_count_temp;
    getline(cin, q_count_temp);

    int q_count = stoi(ltrim(rtrim(q_count_temp)));

    vector<string> q(q_count);

    for (int i = 0; i < q_count; i++) {
        string q_item;
        getline(cin, q_item);

        q[i] = q_item;
    }

    vector<string> result = closestStraightCity(c, x, y, q);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
