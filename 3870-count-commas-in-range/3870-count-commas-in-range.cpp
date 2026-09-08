class Solution {
public:
    int countCommas(int n) {
        int total = 0;
        long long low = 1, high = 9;
        int d = 1;
        while (low <= n) {
            long long curHigh = min(high, (long long)n);
            long long cnt = curHigh - low + 1;
            total += (int)(cnt * ((d - 1) / 3));
            low = high + 1;
            high = high * 10 + 9;
            d++;
        }
        return total;
    }
};