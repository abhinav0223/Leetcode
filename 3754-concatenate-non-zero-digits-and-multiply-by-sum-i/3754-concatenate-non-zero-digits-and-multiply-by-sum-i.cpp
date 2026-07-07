class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;

        string digits = to_string(n);
        long long x = 0;
        long long sum = 0;
        bool hasNonZero = false;

        for (char c : digits) {
            int d = c - '0';
            if (d != 0) {
                x = x * 10 + d;
                sum += d;
                hasNonZero = true;
            }
        }

        if (!hasNonZero) return 0;

        return x * sum;
    }
};