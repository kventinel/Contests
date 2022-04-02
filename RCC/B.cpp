#include <cstdio>

inline long long gcd(long long a, long long b) {
    if (a > b) {
        while (true) {
            if (b == 0) {
                return a;
            }
            a %= b;
            if (a == 0) {
                return b;
            }
            b %= a;
        }
    } else {
        while (true) {
            if (a == 0) {
                return b;
            }
            b %= a;
            if (b == 0) {
                return a;
            }
            a %= b;
        }
    }
}

int main() {
    int tests;
    std::scanf("%d", &tests);
    long long a, b, c, d, temp, p, q, res1, res2;
    for (int test = 0; test < tests; ++test) {
        std::scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        p = a * c / gcd(a, c);
        res1 = p / a * b;
        res2 = p / c * d;
        q = gcd(res1, res2);
        temp = gcd(p, q);
        printf("%lld %lld\n", p / temp, q / temp);
    }
    return 0;
}
