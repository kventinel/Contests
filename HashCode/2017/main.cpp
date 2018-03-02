#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

const int VIDEOS = 10004;
const int ENDP = 1003;
const int REQ = 1000006;
const int CACHES = 1003;
const int CAPAC = 500005;

struct req{
    int vid;
    int town;
    int us;
    int cash;
    double result;

    req() : vid(0), town(0), us(0){}
    req(int newVid, int newTown, int newUs) : vid(newVid), town(newTown), us(newUs) {}

    bool operator<(const req& other) const {
      return result > other.result;
    }

    bool operator!=(const req& other) const {
      return abs(result - other.result) > 0.0000001;
    }
};

ll V, E, R, C, X;
ll video_sz[VIDEOS];  // 10^3
ll endpoints[ENDP];
vector<pll> ribs[ENDP];
map<pll, ll> total_reqs;
vector<req> reqs;
vector<int> videos;
vector<int> cash;
std::vector<std::set<int>> cash_videos;
vector<std::pair<int, int>> result;
multiset<req> request;

ll findMS(req* temp) {
  ll ms = endpoints[temp->town];
  for (auto item : ribs[temp->town]) {
    if (ms > item.second) {
      if (cash_videos[item.second].find(temp->vid) != cash_videos[item.second].end()) {
        ms = min(ms, item.first);
        break;
      }
    } else {
      break;
    }
  }
  return ms;
}

bool getResult(req* temp) {
  ll ms = endpoints[temp->town];
  for (auto item : ribs[temp->town]) {
    if (ms > item.second) {
      if (cash_videos[item.second].find(temp->vid) != cash_videos[item.second].end()) {
        ms = min(ms, item.first);
        break;
      }
    } else {
      break;
    }
  }
  for (auto item : ribs[temp->town]) {
    if (ms < item.second) {
      break;
    }
    if (videos[temp->vid] < cash[item.second]) {
      temp->cash = item.second;
//        temp->result = item.first * (ms - item.second) / log(videos[temp->vid]);
//        temp->result = item.first * (ms - item.second) / videos[temp->vid];
        temp->result = item.first * (ms - item.second);
//      temp->result = item.first * (ms - item.second) / sqrt(videos[temp->vid]);
      return true;
    }
  }
  temp->result = -1;
  return false;
}

void mySolution() {
  int k = 1;
  while (k > 0) {
    std::vector<int> v(V);
    for (int i = 0; i < reqs.size(); ++i) {
      getResult(&reqs[i]);
      if (reqs[i].result > 0) {
        v[reqs[i].vid] += reqs[i].result;
      }
    }
    int mv = 0;
    for (int i = 1; i < V; ++i) {
      if (v[mv] < v[i]) {
        mv = i;
      }
    }
    std::vector<int> h(C);
    for (int i = 0; i < reqs.size(); ++i) {
      if (reqs[i].vid == mv) {
        ll ms = findMS(&reqs[i]);
        for (int j = 0; j < ribs[reqs[i].town].size(); ++j) {
          if (ribs[reqs[i].town][j].first < ms) {
            h[ribs[reqs[i].town][j].second] += ms - ribs[reqs[i].town][j].first;
          }
        }
      }
    }
    int mi = 0;
    for (int i = 1; i < C; ++i) {
      if (h[i] > h[mi]) {
        mi = i;
      }
    }
    result.push_back(std::make_pair(mi, mv));
    cash_videos[mi].insert(mv);
    --k;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> V >> E >> R >> C >> X;
  ll foo, bar, baz;
  for (int i = 0; i < V; ++i) {
    int temp;
    cin >> temp;
    videos.push_back(temp);
  }
  for (int i = 0; i < C; ++i) {
    cash.push_back(X);
    cash_videos.push_back(set<int>());
  }
  for(int i = 0; i < E; ++i){
    cin >> endpoints[i] >> foo;
    for(int j = 0; j < foo; ++j){
      cin >> bar >> baz;
      ribs[i].push_back({baz, bar});
    }
    sort(ribs[i].begin(), ribs[i].end());
  }
  for(int i = 0; i < R; ++i){
    cin >> foo >> bar >> baz;
    req temp(foo, bar, baz);
    getResult(&temp);
    reqs.push_back(temp);
    request.insert(temp);
  }
  mySolution();
  sort(result.begin(), result.end());
  int k = 1;
  for (int i = 1; i < result.size(); ++i) {
    if (result[i].first != result[i - 1].first) {
      ++k;
    }
  }
  cout << k << endl;
  cout << result[0].first << " " << result[0].second;
  for (int i = 1; i < result.size(); ++i) {
    if (result[i].first != result[i - 1].first) {
      cout << endl << result[i].first << " " << result[i].second;
    } else {
      if (result[i].second != result[i - 1].second) {
        cout << " " << result[i].second;
      }
    }
  }
  cout << endl;
  return 0;
}