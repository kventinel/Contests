#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'calculateProfit' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY earning
 *  3. INTEGER_ARRAY cost
 *  4. INTEGER e
 */

int calculateProfit(int n, vector<int> earning, vector<int> cost, int e) {
  vector<int> e1(n + 1);
  vector<int> e2(n + 1);
  for (int i = 0; i < n; ++i) {
    e2[i] = max(e2[i], e1[i] + earning[i] * e);
    e1[i + 1] = max(e1[i + 1], e1[i]);
    e1[i + 1] = max(e1[i + 1], e2[i] - cost[i] * e);
    e2[i + 1] = max(e2[i + 1], e2[i]);
  }
  return max(e1[n], e2[n]);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string earning_count_temp;
    getline(cin, earning_count_temp);

    int earning_count = stoi(ltrim(rtrim(earning_count_temp)));

    vector<int> earning(earning_count);

    for (int i = 0; i < earning_count; i++) {
        string earning_item_temp;
        getline(cin, earning_item_temp);

        int earning_item = stoi(ltrim(rtrim(earning_item_temp)));

        earning[i] = earning_item;
    }

    string cost_count_temp;
    getline(cin, cost_count_temp);

    int cost_count = stoi(ltrim(rtrim(cost_count_temp)));

    vector<int> cost(cost_count);

    for (int i = 0; i < cost_count; i++) {
        string cost_item_temp;
        getline(cin, cost_item_temp);

        int cost_item = stoi(ltrim(rtrim(cost_item_temp)));

        cost[i] = cost_item;
    }

    string e_temp;
    getline(cin, e_temp);

    int e = stoi(ltrim(rtrim(e_temp)));

    int result = calculateProfit(n, earning, cost, e);

    fout << result << "\n";

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
