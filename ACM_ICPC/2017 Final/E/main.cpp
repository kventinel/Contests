#include <iomanip>
#include <iostream>
#include <vector>

int main() {
    int n;
    double t;
    std::cin >> n >> t;
    std::vector<std::pair<double, double>> data(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> data[i].first >> data[i].second;
    }
    double c = 0;
    double step = 1e6;
    while (step > 1e-8) {
        double time = 0;
        for (int i = 0; i < n; ++i) {
            time += data[i].first / std::max(data[i].second + c, 1e-8);
        }
        if (time > t) {
            c += step;
        } else {
            c -= step;
        }
        step /= 2;
    }
    std::cout << std::setprecision(15) << c << std::endl;
    return 0;
}