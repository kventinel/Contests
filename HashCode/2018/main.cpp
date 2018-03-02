#include <bits/stdc++.h>

using namespace std;

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <set>
//
//using namespace std;
//
//struct ride {
//    int a, b, x, y, s, f, i;
//
//    bool operator<(const ride& other) const {
//        if (f != other.f) {
//            return f < other.f;
//        }
//        return s < other.s;
//    }
//};
//
//int dist(pair<int, int> a, pair<int, int> b) {
//    return abs(a.first - b.first) + abs(a.second - b.second);
//}
//
//int R, C, F, N, B, T;
//vector<ride> rides;
//vector<int> cars_time;
//vector<pair<int, int>> car_pos;
//vector<vector<int>> ans;
//
//int main() {
//    freopen("d.in", "r", stdin);
//    freopen("d.out", "w", stdout);
//    cin >> R >> C >> F >> N >> B >> T;
//    rides.resize(N);
//    cars_time.resize(F, 0);
//    car_pos.resize(F, make_pair(0, 0));
//    ans.resize(F);
//    int i = 0;
//    for (ride &a : rides) {
//        cin >> a.a >> a.b >> a.x >> a.y >> a.s >> a.f;
//        a.i = i;
//        ++i;
//    }
//    sort(rides.begin(), rides.end());
//    for (ride a : rides) {
////        D
////        if (dist(make_pair(a.a, a.b), make_pair(a.x, a.y)) < 200) {
////            continue;
////        }
//        int best_car = 0;
//        int time = max(cars_time[0] + dist(car_pos[0], make_pair(a.a, a.b)), a.s);
//        for (int i = 1; i < F; ++i) {
//            //            if (dist(car_pos[i], make_pair(a.a, a.b)) > 1000) {
//            //                continue;
//            //            }
//            if (cars_time[i] + dist(car_pos[i], make_pair(a.a, a.b)) < time && time > a.s) {
//                time = cars_time[i] + dist(car_pos[i], make_pair(a.a, a.b));
//                best_car = i;
//            } else if (cars_time[i] + dist(car_pos[i], make_pair(a.a, a.b)) <= a.s &&
//                       cars_time[i] + dist(car_pos[i], make_pair(a.a, a.b)) >= time) {
//                time = cars_time[i] + dist(car_pos[i], make_pair(a.a, a.b));
//                best_car = i;
//            }
//            //            if (cars_time[i] + dist(car_pos[i], make_pair(a.a, a.b)) < time) {
//            //                time = cars_time[i] + dist(car_pos[i], make_pair(a.a, a.b));
//            //                best_car = i;
//            //            }
//        }
//        time = max(time, a.s);
//        time = time + dist(make_pair(a.a, a.b), make_pair(a.x, a.y));
//        if (time <= a.f) {
//            ans[best_car].push_back(a.i);
//            cars_time[best_car] = time;
//            car_pos[best_car] = make_pair(a.x, a.y);
//        }
//    }
//    for (int i = 0; i < )
//    for (const auto &a : ans) {
//        cout << a.size();
//        for (int b : a) {
//            cout << " " << b;
//        }
//        cout << endl;
//    }
//    return 0;
//}

//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <algorithm>
//#include <set>
//#include <cmath>
//
//using namespace std;
//
int R, C, F, N, B, T;

struct Point {
    Point() {
        x = 0;
        y = 0;
    }
    Point(int x_pos, int y_pos) {
        x = x_pos;
        y = y_pos;
    }
    int x, y;

    friend int operator-(const Point &f, const Point &s) {
        return fabs(f.x - s.x) + fabs(f.y - s.y);
    }

    friend istream& operator>>(istream &os, Point &s) {
        os >> s.x >> s.y;
        return os;
    }
};
//
struct ride {
    Point start;
    Point finish;
    int s, f, i;

    bool operator<(const ride& other) const {
        return f - (finish - start) < other.f - (other.finish - other.start);
    }
};

vector<ride> rides;


int dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}


int check_score(std::vector<std::vector<int>> &assignments) {
    int score = 0;
    sort(rides.begin(), rides.end(), [](const ride &a, const ride &b) {
        return a.i <  b.i;
    });
    for (int car_num = 0; car_num < assignments.size(); car_num++) {
        Point pos = Point(0, 0);
        int time = 0;
        for (int ride : assignments[car_num]) {
            time += fabs(pos - rides[ride].start);
            int time_arrive = time;
            time = max(time, rides[ride].s);
            time += fabs(rides[ride].start - rides[ride].finish);
            if (time > T) {
                break;
            }
            if (time_arrive <= rides[ride].s) {
                score += B;
            }
            if (time <= rides[ride].f) {
                score += rides[ride].start - rides[ride].finish;
            }
            pos = rides[ride].finish;
        }
    }
    return score;
}

int main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    cin >> R >> C >> F >> N >> B >> T;
    rides.resize(N);
    int i = 0;
    for (ride &a : rides) {
        cin >> a.start >> a.finish >> a.s >> a.f;
        a.i = i;
        ++i;
    }
//    sort(rides.begin(), rides.end());
    vector<vector<int>> best_ans;
    int best_score = 0;
    for (int r = 0; r < 1; ++r) {
//        random_shuffle(rides.begin(), rides.end());
        sort(rides.begin(), rides.end());
        vector<int> cars_time(F, 0);
        vector<Point> car_pos(F);
        for (int i = 0; i < F; ++i) {
            car_pos[i] = Point(0, 0);
        }
        vector<vector<int>> ans(F);
        for (ride a : rides) {
//            if (a.start - a.finish < 500) {
//                continue;
//            }
            int best_car = 0;
            int time = cars_time[0] + (car_pos[0] - a.start);
            int best_dist = INT32_MAX;
            for (int i = 1; i < F; ++i) {
//                if (car_pos[i] - a.start > 500) {
//                    continue;
//                }
                if (cars_time[i] + (car_pos[i] - a.start) < time && time > a.s) {
                    time = cars_time[i] + (car_pos[i] - a.start);
                    best_car = i;
                } else if (cars_time[i] + (car_pos[i] - a.start) <= a.s && cars_time[i] + (car_pos[i] - a.start) >= time) {
                    time = cars_time[i] + (car_pos[i] - a.start);
                    best_car = i;
                }
//                if (cars_time[i] + (car_pos[i] - a.start) < time && time > a.s) {
//                    time = cars_time[i] + (car_pos[i] - a.start);
//                    best_car = i;
//                } else if (cars_time[i] + (car_pos[i] - a.start) <= a.s && (car_pos[i] - a.start) < best_dist) {
//                    best_dist = (car_pos[i] - a.start);
//                    best_car = i;
//                    time = cars_time[i] + (car_pos[i] - a.start);
//                }
            }
            time = max(time, a.s);
            time = time + (a.start - a.finish);
            if (time <= a.f) {
                ans[best_car].push_back(a.i);
                cars_time[best_car] = time;
                car_pos[best_car] = a.finish;
            }
        }
        int score = check_score(ans);
        std::cerr << score << std::endl;
        if (best_score < score) {
            best_score = score;
            best_ans = ans;
        }
    }
    for (const auto &a : best_ans) {
        cout << a.size();
        for (int b : a) {
            cout << " " << b;
        }
        cout << endl;
    }
    return 0;
}

//void reorder_rides(std::vector<int> &ride_ids) {
//    sort(ride_ids.begin(), ride_ids.end(), [&](int a, int b) {
//        return rides[a].s < rides[b].s;
//    });
//}
//
//int main() {
//    freopen("d.out", "r", stdin);
//    fstream fin("d.in");
//    freopen("d2.out", "w", stdout);
//    int F = 400;
//    int N = 10000;
//    vector<vector<int>> ans(F);
//    vector<int> temp(N);
//    for (int i = 0; i < F; ++i) {
//        int c;
//        cin >> c;
//        for (int j = 0; j < c; ++j) {
//            int a;
//            cin >> a;
//            ans[i].push_back(a);
//            temp[a] = i;
//        }
//    }
//    rides.resize(N);
//    int i = 0;
//    for (ride &a : rides) {
//        cin >> a.start >> a.finish >> a.s >> a.f;
//        a.i = i;
//        ++i;
//    }
//    for (int i = 0; i < F; ++i) {
//        reorder_rides(ans[i]);
//    }
//    cout << check_score(ans) << endl;
//}
