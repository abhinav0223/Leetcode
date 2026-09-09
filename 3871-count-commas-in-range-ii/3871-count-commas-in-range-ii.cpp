class Solution {
public:
    long long countCommas(long long n) {
        long long total = 0;
        long long lower = 1;
        for (int d = 1; lower <= n; d++) {
            long long upper = lower * 10 - 1;
            long long high = min(n, upper);
            long long count = high - lower + 1;
            long long commas = (d - 1) / 3;
            total += count * commas;
            lower *= 10;
        }
        return total;
    }
};