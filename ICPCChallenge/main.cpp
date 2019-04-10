#include <iostream>
#include <fstream>
#include <vector>
#include <random>
using namespace std;

const int CLASS = 10;

int score(const vector<vector<int> > &weights, const vector<vector<int> > &X, const vector<int> &Y) {
  int res = 0;
  for (int i = 0; i < X.size(); ++i) {
    vector<int> vals(CLASS * 15);
    for (int j = 0; j < CLASS * 15; ++j) {
      for (int g = 0; g < 51; ++g) {
        vals[j] += weights[j][g] * X[i][g];
      }
    }
    for (int j = 0; j < CLASS * 15; ++j) {
      if (vals[j] > 0) {
        vals[j] = 1;
      } else {
        vals[j] = -1;
      }
    }
    for (int j = 0; j < CLASS; ++j) {
      for (int k = 1; k < 15; ++k) {
        vals[j * 15] += vals[j * 15 + k];
      }
    }
    int best = 0;
    for (int j = 1; j < CLASS; ++j) {
      if (vals[j * 15] > vals[best * 15]) {
        best = j;
      }
    }
    if (best == Y[i]) {
      ++res;
    }
  }
  return res;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  ifstream fin2("A/res");
  ofstream fout("A/res2"); 
  ifstream fin1("A/mnist10_train.txt");
  vector<vector<int> > X;
  vector<int> Y;
  int val;
  while (fin1 >> val) {
    X.emplace_back(51);
    X.back()[0] = val;
    for (int i = 1; i < X.back().size(); ++i) {
      fin1 >> X.back()[i];
    }
    fin1 >> val;
    Y.push_back(val);
  }
  vector<vector<int> > weights(CLASS * 15, vector<int> (51));
  for (int i = 0; i < CLASS; ++i) {
    for (int j = 0; j < 15; ++j) {
      for (int k = 0; k < 51; ++k) {
        double d;
        fin2 >> d;
        if (d > 0) {
          weights[i * 15 + j][k] = 1;
        } else {
          weights[i * 15 + j][k] = -1;
        }
      }
    }
  }
  mt19937 gen(42);
  int last_score = score(weights, X, Y);
  cout << last_score << endl;
  for (int i = 0; i < 100; ++i) {
    int a = uniform_int_distribution<>(0, 15 * CLASS - 1)(gen);
    int b = uniform_int_distribution<>(0, 50)(gen);
    int c = uniform_int_distribution<>(0, 50)(gen);
int d = uniform_int_distribution<>(0, 15 * CLASS - 1)(gen);
    weights[a][b] *= -1;
    weights[d][c] *= -1;
    int sc = score(weights, X, Y);
    cout << sc << endl;
    if (sc <= last_score) {
      weights[a][b] *= -1;
      weights[d][c] *= -1;
    } else {
      last_score = sc;
    }
  }
  for (auto i : weights) {
    for (auto j : i) {
      fout << j << " ";
    }
    fout << endl;
  }
  return 0;
}
