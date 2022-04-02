#include <iostream>
#include <vector>

int main() {
    int64_t d, k;
    std::cin >> d >> k;
    std::vector<int64_t> pixels(256);
    for (int64_t i = 0; i < d; ++i) {
        int64_t r;
        std::cin >> r;
        std::cin >> pixels[r];
    }
    std::vector<std::vector<int64_t>> dp(k + 1, std::vector<int64_t> (256, INT64_MAX));
    for (int64_t i = 0; i < 256; ++i) {
        int64_t sum = 0;
        for (int64_t j = 0; j < i; ++j) {
            sum += pixels[j] * (i - j) * (i - j);
        }
        dp[1][i] = sum;
    }
    for (int64_t i = 2; i <= k; ++i) {
        for (int64_t j = i - 1; j < 256; ++j) {
            for (int64_t l = i - 2; l < j; ++l) {
                int64_t sum =
                        dp[i - 1][l];
                for (int64_t e = l + 1; e < j; ++e) {
                    sum += pixels[e] * std::min(j - e, e - l) * std::min(j - e, e - l);
                }
                dp[i][j] = std::min(sum, dp[i][j]);
            }
        }
    }
    int64_t res = INT64_MAX;
    for (int64_t i = k - 1; i < 256; ++i) {
        int64_t sum = dp[k][i];
        for (int64_t j = i + 1; j < 256; ++j) {
            sum += pixels[j] * (j - i) * (j - i);
        }
        res = std::min(res, sum);
    }
    std::cout << res << std::endl;
    return 0;
}