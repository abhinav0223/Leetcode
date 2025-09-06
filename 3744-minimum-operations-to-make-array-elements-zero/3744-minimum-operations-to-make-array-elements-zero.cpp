class Solution {
public:
    using int64 = long long;
    long long totalSteps(long long n) {
        if (n <= 0)
            return 0;
        long long steps = 0;
        long long start = 1;
        int k = 1;
        while (start <= n) {
            long long end = min(n, (1LL << (2 * k)) - 1);
            steps += (end - start + 1) * 1LL * k;
            start <<= 2;
            k++;
        }
        return steps;
    }
    long long rangeSteps(long long l, long long r) {
        return totalSteps(r) - totalSteps(l - 1);
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long result = 0;
        for (auto& q : queries) {
            long long l = q[0], r = q[1];
            long long steps = rangeSteps(l, r);
            result += (steps + 1) / 2;
        }
        return result;
    }
};
