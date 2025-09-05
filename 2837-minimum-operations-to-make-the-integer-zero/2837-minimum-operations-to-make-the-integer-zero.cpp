class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (long long m = 1; m <= 60; m++) {
            long long val = num1 - m * 1LL * num2;
            if (val < m) continue; // can't split into m powers of two
            if (__builtin_popcountll(val) <= m) return m;
        }
        return -1;
    }
};
